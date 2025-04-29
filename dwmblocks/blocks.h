/* Catppuccin Mocha color palette */
// static const char *colors[] = {
//     "#1e1e2e", /* base (background) */
//     "#cdd6f4", /* text (foreground) */
//     "#f38ba8", /* red */
//     "#a6e3a1", /* green */
//     "#f9e2af", /* yellow */
//     "#89b4fa", /* blue */
//     "#f5c2e7", /* pink */
//     "#94e2d5", /* cyan */
//     "#bac2de", /* white */
//     "#585b70", /* black (bright) */
//     "#fab387", /* orange */
//     "#b4befe", /* purple */
//     "#74c7ec", /* aqua */
//     "#89dceb", /* selection background */
//     "#f5e0dc", /* selection foreground */
// };

// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.

static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {" ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 1, 0},
    // {"", "~/suckless/dwmblocks/Scripts/cpu.sh", 5, 0},
    {"", "~/suckless/dwmblocks/Scripts/dwm-cpu-temp.sh", 5, 0},
    {"", "~/suckless/dwmblocks/Scripts/dwm-bat.sh", 242, 0},
    {"💻", "brightnessctl | grep -o '[0-9]\\+%' | head -1", 3, 0},
    {"", "~/suckless/dwmblocks/Scripts/vol.sh", 3, 0},
    {"", "~/suckless/dwmblocks/Scripts/dwm-net.sh", 30, 0},
    {"", "~/suckless/dwmblocks/Scripts/dwm-disk.sh", 250, 0},
    {"", "~/suckless/dwmblocks/Scripts/check_updates.sh", 18000, 0},
    {"", "date '+%b %d (%a) %I:%M%p'", 5, 0},
};

// sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
