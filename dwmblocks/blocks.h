//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" :", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
	{"", "~/suckless/dwmblocks/Scripts/cpu.sh", 30, 0},
	{"", "~/suckless/dwmblocks/Scripts/bat.sh", 30, 0},
	{"", "brightnessctl | grep -o '[0-9]\\+%' | head -1", 5, 0},
	{"", "~/suckless/dwmblocks/Scripts/vol.sh", 30, 0},
	{"", "~/suckless/dwmblocks/Scripts/net.sh", 30, 0},
	{"", "~/suckless/dwmblocks/Scripts/disk.sh", 30, 0},
	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

/* static const char *fonts[] = { */
/*     "JetBrains Mono:size=17", // Use your JetBrainsMonoNL configuration */
/* }; */

