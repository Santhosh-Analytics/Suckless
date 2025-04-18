// Minimal dwl-ipc client (save as dwl-ipc.c)
#include "dwl-ipc-unstable-v2-protocol.h"
#include <stdio.h>
#include <wayland-client.h>

int main() {
  struct wl_display *display = wl_display_connect(NULL);
  if (!display) {
    fprintf(stderr, "Failed to connect to Wayland display\n");
    return 1;
  }
  printf("dwl IPC client connected\n");
  wl_display_disconnect(display);
  return 0;
}
