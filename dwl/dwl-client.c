// dwl-client.c
#include "dwl-ipc-unstable-v2-protocol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wayland-client.h>

static void handle_tags(void *data, struct zext_dwl_tags_v1 *tags,
                        const char *taglist) {
  printf("Tags: %s\n", taglist);
}

static void handle_focused(void *data, struct zext_dwl_focused_v1 *focused,
                           const char *title) {
  printf("Focused: %s\n", title);
}

static const struct zext_dwl_tags_v1_listener tags_listener = {
    .taglist = handle_tags,
};

static const struct zext_dwl_focused_v1_listener focused_listener = {
    .title = handle_focused,
};

int main() {
  struct wl_display *display = wl_display_connect(NULL);
  if (!display) {
    fprintf(stderr, "Failed to connect to Wayland display\n");
    return 1;
  }

  struct wl_registry *registry = wl_display_get_registry(display);
  wl_display_roundtrip(display); // Needed to populate registry

  // Listener & proxy placeholder
  struct zext_dwl_ipc_manager_v1 *ipc_manager = NULL;

  // Registry handler to bind IPC manager
  static void registry_handler(void *data, struct wl_registry *registry,
                               uint32_t id, const char *interface,
                               uint32_t version) {
    if (strcmp(interface, "zext_dwl_ipc_manager_v1") == 0) {
      *(struct zext_dwl_ipc_manager_v1 **)data =
          wl_registry_bind(registry, id, &zext_dwl_ipc_manager_v1_interface, 1);
    }
  }

  static const struct wl_registry_listener registry_listener = {
      .global = registry_handler,
      .global_remove = NULL,
  };

  wl_registry_add_listener(registry, &registry_listener, &ipc_manager);
  wl_display_roundtrip(display);

  if (!ipc_manager) {
    fprintf(stderr, "IPC manager not found in registry.\n");
    wl_display_disconnect(display);
    return 1;
  }

  struct zext_dwl_tags_v1 *tags = zext_dwl_ipc_manager_v1_get_tags(ipc_manager);
  struct zext_dwl_focused_v1 *focused =
      zext_dwl_ipc_manager_v1_get_focused(ipc_manager);

  zext_dwl_tags_v1_add_listener(tags, &tags_listener, NULL);
  zext_dwl_focused_v1_add_listener(focused, &focused_listener, NULL);

  // Read events
  wl_display_roundtrip(display);

  zext_dwl_tags_v1_destroy(tags);
  zext_dwl_focused_v1_destroy(focused);
  zext_dwl_ipc_manager_v1_destroy(ipc_manager);
  wl_display_disconnect(display);

  return 0;
}
