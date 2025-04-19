#include <stdio.h>
#include <wayland-client.h>
#include "dwl-ipc-unstable-v2-protocol.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }
    printf("dwl IPC placeholder - replace with full implementation\n");
    return 0;
}
