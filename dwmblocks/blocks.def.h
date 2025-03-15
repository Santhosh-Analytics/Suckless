// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.

static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {" ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 5, 0},
    // {"", "~/suckless/dwmblocks/Scripts/cpu.sh", 5, 0},
    {"", "~/suckless/dwmblocks/Scripts/cputemp.sh", 5, 0},
    {"", "~/suckless/dwmblocks/Scripts/bat.sh", 242, 0},
    {"", "brightnessctl | grep -o '[0-9]\\+%' | head -1", 3, 0},
    {"", "~/suckless/dwmblocks/Scripts/vol.sh", 3, 0},
    {"", "~/suckless/dwmblocks/Scripts/net.sh", 30, 0},
    {"", "~/suckless/dwmblocks/Scripts/disk.sh", 250, 0},
    {"", "~/suckless/dwmblocks/Scripts/check_updates.sh", 18000, 0},
    {"", "date '+%b %d (%a) %I:%M%p'", 5, 0},
};

// sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
// static const unsigned int alphas[][3] = {
//     /*               fg      bg        border*/
//     [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
//     [SchemeSel] = {OPAQUE, baralpha, borderalpha},
// };
//
/* static const char *fonts[] = { */
/*     "JetBrains Mono:size=17", // Use your JetBrainsMonoNL configuration */
/* }; */
