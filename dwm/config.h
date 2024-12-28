/*  ____ _____  */
/* |  _ \_   _|  Derek Taylor (DistroTube) */
/* | | | || |  	http://www.youtube.com/c/DistroTube */
/* | |_| || |  	http://www.gitlab.com/dwt1/dwm-distrotube */
/* |____/ |_|  	*/

/* See LICENSE file for copyright and license details. */
#include <X11/keysym.h>
#include <X11/keysymdef.h>
#define XF86MonBrightnessUp 0x1008FF02
#define XF86MonBrightnessDown 0x1008FF03

/* appearance */
static const unsigned int borderpx = 5; /* border pixel of windows */
static const unsigned int gappx = 5;    /* gaps between windows */
static const unsigned int snap = 32;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const int horizpadbar = 5;       /* horizontal padding for statusbar */
static const int vertpadbar = 5;        /* vertical padding for statusbar */
/* Default font will be Ubuntu if installed (ttf-ubuntu).
 * Otherwise, your default font will be Hack (ttf-hack)
 * JoyPixels (ttf-joypixels) is a dependency for colored fonts and emojis.
 */
static const char *fonts[] = {"JetBrainsMonoNL:size=12:style=Bold",
                              "Font Awesome 6 Free Solid:size=13",
                              "Hack:size=12:antialias=true:autohint=true",
                              "JoyPixels:size=12:antialias=true:autohint=true"};
static const char dmenufont[] = "JetBrainsMonoNL:size=14:style=Bold";
#include "/home/San/.cache/wal/colors-wal-dwm.h"
// static const char col_1[] = "#282c34"; /* background color of bar */
// static const char col_2[] = "#282c34"; /* border color unfocused windows */
// static const char col_3[] = "#d7d7d7";
// static const char col_4[] =
//     "#924441"; /* border color focused windows and tags */
// static const char col_cyan[] = "#005577";

/* bar opacity
 * 0xff is no transparency.
 * 0xee adds wee bit of transparency.
 * 0xdd adds adds a bit more transparency.
 * Play with the value to get desired transparency.
 */
#define OPAQUE 0xffU
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
// static const char *colors[][3] = {
//     /*               fg         bg         border   */
//     [SchemeNorm] = {col_3, col_1, col_2},
//     [SchemeSel] = {col_3, col_cyan, col_4},
// };
#define TRANSPARENT 0x00
static const unsigned int alphas[][3] = {
    /*               fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
};

/* tagging */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
 */
/* static const char *tags[] = { "", "", "", "", "", "",
 * "", "", "" }; */
static const char *tags[] = {"1", "2", "3", "4", "5"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    0; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

#include "grid.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle}, {"HHH", grid}, {NULL, NULL},
};

/* key definitions */
#define MODKEY Mod4Mask

#define TAGKEYS(KEY, TAG)                                                      \
  {1, {{MODKEY, KEY}}, view, {.ui = 1 << TAG}},                                \
      {1, {{MODKEY | ControlMask, KEY}}, toggleview, {.ui = 1 << TAG}},        \
      {1, {{MODKEY | ShiftMask, KEY}}, tag, {.ui = 1 << TAG}},                 \
      {1,                                                                      \
       {{MODKEY | ControlMask | ShiftMask, KEY}},                              \
       toggletag,                                                              \
       {.ui = 1 << TAG}},
//
// /* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/zsh", "-c", cmd, NULL }                      \
  }

// /* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
// static const char *dmenucmd[] = {"dmenu-run", NULL};
static const char *dmenucmd[] = {"dmenu_run", NULL};
static const char *termcmd[] = {"st", NULL};
// static const char *tabtermcmd[] = {"tabbed", "-r", "2", "st", "-w", "''",
// NULL};

/* First, define the clipmenud command */
static const char *clipmenud_restart[] = {
    "sh", "-c",
    "pkill clipmenud; rm -f ~/.local/share/clipmenu/daemon.lock; sleep 1; "
    "clipmenud -l debug -t 'text/plain;charset=utf-8' -t 'image/png'",
    NULL};

static const char *clipcmd[] = {"clipmenu", "-p", "San's Clip History",
                                "-l",       "20", NULL};

static const char *flameshot[] = {
    "sh", "-c",
    "flameshot gui --raw | xclip -selection clipboard -t image/png -i", NULL};
// static const char *xclipcmd[] = {"sh", "-c", "flameshot gui | xclip
// -selection clipboard -t image/png", NULL};

static Keychord keychords[] = {
    /* Keys        function        argument */
    {1, {{MODKEY, XK_p}}, spawn, {.v = dmenucmd}},
    {1, {{MODKEY, XK_Return}}, spawn, {.v = termcmd}},
    // {1, {{Mod1Mask, XK_Return}}, spawn, {.v = tabtermcmd}},
    {1, {{MODKEY, XK_c}}, killclient, {0}},

    /* Dmenu scripts launched with emacs-style keychords SUPER + p followed
    by
       "key" */
    // {2, {{MODKEY, XK_p}, {0, XK_e}}, spawn, SHCMD("dm-confedit")},
    // {2, {{MODKEY, XK_p}, {0, XK_i}}, spawn, SHCMD("dm-maim")},
    // {2, {{MODKEY, XK_p}, {0, XK_k}}, spawn, SHCMD("dm-kill")},
    // {2, {{MODKEY, XK_p}, {0, XK_l}}, spawn, SHCMD("dm-logout")},
    // {2, {{MODKEY, XK_p}, {0, XK_m}}, spawn, SHCMD("dm-man")},
    // {2, {{MODKEY, XK_p}, {0, XK_r}}, spawn, SHCMD("dm-reddit")},
    // {2, {{MODKEY, XK_p}, {0, XK_s}}, spawn, SHCMD("dm-websearch")},
    // {2, {{MODKEY, XK_p}, {0, XK_p}}, spawn, SHCMD("passmenu")},

    //     {2, {{MODKEY, XK_e}, {0, XK_e}}, spawn, SHCMD("emacsclient -c -a
    //     'emacs'")}, {2,
    //      {{MODKEY, XK_e}, {0, XK_a}},
    //      spawn,
    //      SHCMD("emacsclient -c -a 'emacs' --eval '(emms)' --eval "
    //            "'(emms-play-directory-tree \"~/Music/\")'")},
    //     {2,
    //      {{MODKEY, XK_e}, {0, XK_b}},
    //      spawn,
    //      SHCMD("emacsclient -c -a 'emacs' --eval '(ibuffer)'")},
    //     {2,
    //      {{MODKEY, XK_e}, {0, XK_d}},
    //      spawn,
    //      SHCMD("emacsclient -c -a 'emacs' --eval '(dired nil)'")},
    //     {2,
    //      {{MODKEY, XK_e}, {0, XK_i}},
    //      spawn,
    //      SHCMD("emacsclient -c -a 'emacs' --eval '(erc)'")},
    //     {2,
    //      {{MODKEY, XK_e}, {0, XK_n}},
    //      spawn,
    //      SHCMD("emacsclient -c -a 'emacs' --eval '(elfeed)'")},
    //     {2,
    //      {{MODKEY, XK_e}, {0, XK_s}},
    //      spawn,
    //      SHCMD("emacsclient -c -a 'emacs' --eval '(eshell)'")},
    //     {2,
    //      {{MODKEY, XK_e}, {0, XK_v}},
    //      spawn,
    //      SHCMD("emacsclient -c -a 'emacs' --eval '(+vterm/here nil)'")},
    //     {2,
    //      {{MODKEY, XK_e}, {0, XK_w}},
    //      spawn,
    //      SHCMD("emacsclient -c -a 'emacs' --eval
    //      '(doom/window-maximize-buffer(eww "
    //            "\"distro.tube\"))'")},
    //
    //     /* Web browsers */
    {1, {{MODKEY, XK_w}}, spawn, SHCMD("brave-beta")},
    {1, {{MODKEY | ShiftMask | ControlMask, XK_s}}, spawn, SHCMD("wlogout")},
    {1, {{MODKEY, XK_n}}, spawn, SHCMD("obsidian")},
    {1, {{MODKEY, XK_e}}, spawn, SHCMD("thunderbird")},
    {1, {{MODKEY, XK_f}}, spawn, SHCMD("pcmanfm")},
    {1, {{0, XF86MonBrightnessUp}}, spawn, SHCMD("brightnessctl set +10%")},
    {1, {{0, XF86MonBrightnessDown}}, spawn, SHCMD("brightnessctl set 10%-")},
    {1, {{MODKEY, XK_Up}}, spawn, SHCMD("brightnessctl set +10%")},
    {1, {{MODKEY, XK_Down}}, spawn, SHCMD("brightnessctl set 10%-")},
    {1,
     {{MODKEY, XK_Right}},
     spawn,
     SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%")},
    {1,
     {{MODKEY, XK_Left}},
     spawn,
     SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%")},
    {1, {{0, XK_Print}}, spawn, {.v = flameshot}},

    {1, {{MODKEY | ShiftMask, XK_s}}, spawn, {.v = flameshot}},
    {1, {{MODKEY, XK_v}}, spawn, {.v = clipcmd}},
    {1, {{MODKEY | ShiftMask, XK_c}}, spawn, {.v = clipmenud_restart}},
    //     {1,
    //      {{MODKEY | Mod1Mask, XK_s}},
    //      spawn,
    //      SHCMD("tabbed -r 2 surf -pe x '.surf/html/homepage.html'")},
    //
    {1, {{MODKEY, XK_b}}, togglebar, {0}},
    {1, {{MODKEY, XK_j}}, focusstack, {.i = +1}},
    {1, {{MODKEY, XK_k}}, focusstack, {.i = -1}},
    {1, {{MODKEY | ShiftMask, XK_j}}, rotatestack, {.i = +1}},
    {1, {{MODKEY | ShiftMask, XK_k}}, rotatestack, {.i = -1}},
    {1, {{MODKEY, XK_i}}, incnmaster, {.i = +1}},
    {1, {{MODKEY, XK_d}}, incnmaster, {.i = -1}},
    {1, {{MODKEY, XK_h}}, setmfact, {.f = -0.05}},
    {1, {{MODKEY, XK_l}}, setmfact, {.f = +0.05}},
    {1, {{MODKEY | ShiftMask, XK_Return}}, zoom, {0}},
    {1, {{MODKEY, XK_Tab}}, view, {0}},

    //     /* Layout manipulation */
    {1, {{MODKEY, XK_backslash}}, cyclelayout, {.i = -1}},
    {1, {{MODKEY | ShiftMask, XK_backslash}}, cyclelayout, {.i = +1}},
    {1, {{MODKEY, XK_t}}, setlayout, {.v = &layouts[0]}},
    {2, {{MODKEY, XK_1}, {0, XK_e}}, setlayout, {.v = &layouts[1]}},
    {1, {{MODKEY, XK_m}}, setlayout, {.v = &layouts[2]}},
    {1, {{MODKEY, XK_g}}, setlayout, {.v = &layouts[3]}},
    {1, {{MODKEY, XK_space}}, setlayout, {0}},

    {1, {{MODKEY | ShiftMask, XK_space}}, togglefloating, {0}},
    {1, {{MODKEY, XK_0}}, view, {.ui = ~0}},
    {1, {{MODKEY | ShiftMask, XK_0}}, tag, {.ui = ~0}},

    /* Switching between monitors */
    {1, {{MODKEY, XK_comma}}, focusmon, {.i = -1}},
    {1, {{MODKEY, XK_period}}, focusmon, {.i = +1}},
    {1, {{MODKEY | ShiftMask, XK_comma}}, tagmon, {.i = -1}},
    {1, {{MODKEY | ShiftMask, XK_period}}, tagmon, {.i = +1}},

    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)

    /* Restart or quit dwm */
    {1, {{MODKEY | ShiftMask, XK_r}}, quit, {1}},
    {1, {{MODKEY | ShiftMask, XK_q}}, quit, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
