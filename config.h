/* See LICENSE file for copyright and license details. */

/*
 * appearance
 *
 * font: see http://freedesktop.org/software/fontconfig/fontconfig-user.html
 */
char font[] = "creep2:pixelsize=11:minspace=true";

/* disable bold, italic and roman fonts globally */
static int disablebold = 1;
static int disableitalic = 1;
static int disableroman = 1;

static int borderpx = 2;

/*
 * What program is execed by st depends of these precedence rules:
 * 1: program passed with -e
 * 2: utmp option
 * 3: SHELL environment variable
 * 4: value of shell in /etc/passwd
 * 5: value of shell in config.h
 */
static char *shell = "/bin/sh";
char *utmp = NULL;
char *stty_args = "stty raw pass8 nl -echo -iexten -cstopb 38400";

/* identification sequence returned in DA and DECID */
char *vtiden = "\033[?6c";

/* Kerning / character bounding-box multipliers */
static float cwscale = 1.0;
static float chscale = 1.0;

/*
 * word delimiter string
 *
 * More advanced example: " `'\"()[]{}"
 */
wchar_t *worddelimiters = L" ";

/* selection timeouts (in milliseconds) */
static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;

/* alt screens */
int allowaltscreen = 1;

/* frames per second st should at maximum draw to the screen */
static unsigned int xfps = 120;
static unsigned int actionfps = 30;

/*
 * blinking timeout (set to 0 to disable blinking) for the terminal blinking
 * attribute.
 */
static unsigned int blinktimeout = 800;

/*
 * thickness of underline and bar cursors
 */
static unsigned int cursorthickness = 2;

/*
 * bell volume. It must be a value between -100 and 100. Use 0 for disabling
 * it
 */
static int bellvolume = 0;

/* default TERM value */
char *termname = "xterm-256color";

/*
 * spaces per tab
 *
 * When you are changing this value, don't forget to adapt the »it« value in
 * the st.info and appropriately install the st.info in the environment where
 * you use this st version.
 *
 *	it#$tabspaces,
 *
 * Secondly make sure your kernel is not expanding tabs. When running `stty
 * -a` »tab0« should appear. You can tell the terminal to not expand tabs by
 *  running following command:
 *
 *	stty tabs
 */
unsigned int tabspaces = 8;

/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {
	/* solarized dark */
	"#073642",  /*  0: black    */
	"#dc322f",  /*  1: red      */
	"#859900",  /*  2: green    */
	"#b58900",  /*  3: yellow   */
	"#268bd2",  /*  4: blue     */
	"#d33682",  /*  5: magenta  */
	"#2aa198",  /*  6: cyan     */
	"#eee8d5",  /*  7: white    */
	"#002b36",  /*  8: brblack  */
	"#cb4b16",  /*  9: brred    */
	"#586e75",  /* 10: brgreen  */
	"#657b83",  /* 11: bryellow */
	"#839496",  /* 12: brblue   */
	"#6c71c4",  /* 13: brmagenta*/
	"#93a1a1",  /* 14: brcyan   */
	"#fdf6e3",  /* 15: brwhite  */

/* standard xterm colors */
/* #000000 */
/* #800000 */
/* #008000 */
/* #808000 */
/* #000080 */
/* #800080 */
/* #008080 */
/* #c0c0c0 */
/* #808080 */
/* #ff0000 */
/* #00ff00 */
/* #ffff00 */
/* #0000ff */
/* #ff00ff */
/* #00ffff */
/* #ffffff */
"#000000",
"#00005f",
"#000087",
"#0000af",
"#0000d7",
"#0000ff",
"#005f00",
"#005f5f",
"#005f87",
"#005faf",
"#005fd7",
"#005fff",
"#008700",
"#00875f",
"#008787",
"#0087af",
"#0087d7",
"#0087ff",
"#00af00",
"#00af5f",
"#00af87",
"#00afaf",
"#00afd7",
"#00afff",
"#00d700",
"#00d75f",
"#00d787",
"#00d7af",
"#00d7d7",
"#00d7ff",
"#00ff00",
"#00ff5f",
"#00ff87",
"#00ffaf",
"#00ffd7",
"#00ffff",
"#5f0000",
"#5f005f",
"#5f0087",
"#5f00af",
"#5f00d7",
"#5f00ff",
"#5f5f00",
"#5f5f5f",
"#5f5f87",
"#5f5faf",
"#5f5fd7",
"#5f5fff",
"#5f8700",
"#5f875f",
"#5f8787",
"#5f87af",
"#5f87d7",
"#5f87ff",
"#5faf00",
"#5faf5f",
"#5faf87",
"#5fafaf",
"#5fafd7",
"#5fafff",
"#5fd700",
"#5fd75f",
"#5fd787",
"#5fd7af",
"#5fd7d7",
"#5fd7ff",
"#5fff00",
"#5fff5f",
"#5fff87",
"#5fffaf",
"#5fffd7",
"#5fffff",
"#870000",
"#87005f",
"#870087",
"#8700af",
"#8700d7",
"#8700ff",
"#875f00",
"#875f5f",
"#875f87",
"#875faf",
"#875fd7",
"#875fff",
"#878700",
"#87875f",
"#878787",
"#8787af",
"#8787d7",
"#8787ff",
"#87af00",
"#87af5f",
"#87af87",
"#87afaf",
"#87afd7",
"#87afff",
"#87d700",
"#87d75f",
"#87d787",
"#87d7af",
"#87d7d7",
"#87d7ff",
"#87ff00",
"#87ff5f",
"#87ff87",
"#87ffaf",
"#87ffd7",
"#87ffff",
"#af0000",
"#af005f",
"#af0087",
"#af00af",
"#af00d7",
"#af00ff",
"#af5f00",
"#af5f5f",
"#af5f87",
"#af5faf",
"#af5fd7",
"#af5fff",
"#af8700",
"#af875f",
"#af8787",
"#af87af",
"#af87d7",
"#af87ff",
"#afaf00",
"#afaf5f",
"#afaf87",
"#afafaf",
"#afafd7",
"#afafff",
"#afd700",
"#afd75f",
"#afd787",
"#afd7af",
"#afd7d7",
"#afd7ff",
"#afff00",
"#afff5f",
"#afff87",
"#afffaf",
"#afffd7",
"#afffff",
"#d70000",
"#d7005f",
"#d70087",
"#d700af",
"#d700d7",
"#d700ff",
"#d75f00",
"#d75f5f",
"#d75f87",
"#d75faf",
"#d75fd7",
"#d75fff",
"#d78700",
"#d7875f",
"#d78787",
"#d787af",
"#d787d7",
"#d787ff",
"#d7af00",
"#d7af5f",
"#d7af87",
"#d7afaf",
"#d7afd7",
"#d7afff",
"#d7d700",
"#d7d75f",
"#d7d787",
"#d7d7af",
"#d7d7d7",
"#d7d7ff",
"#d7ff00",
"#d7ff5f",
"#d7ff87",
"#d7ffaf",
"#d7ffd7",
"#d7ffff",
"#ff0000",
"#ff005f",
"#ff0087",
"#ff00af",
"#ff00d7",
"#ff00ff",
"#ff5f00",
"#ff5f5f",
"#ff5f87",
"#ff5faf",
"#ff5fd7",
"#ff5fff",
"#ff8700",
"#ff875f",
"#ff8787",
"#ff87af",
"#ff87d7",
"#ff87ff",
"#ffaf00",
"#ffaf5f",
"#ffaf87",
"#ffafaf",
"#ffafd7",
"#ffafff",
"#ffd700",
"#ffd75f",
"#ffd787",
"#ffd7af",
"#ffd7d7",
"#ffd7ff",
"#ffff00",
"#ffff5f",
"#ffff87",
"#ffffaf",
"#ffffd7",
"#ffffff",
"#080808",
"#121212",
"#1c1c1c",
"#262626",
"#303030",
"#3a3a3a",
"#444444",
"#4e4e4e",
"#585858",
"#626262",
"#6c6c6c",
"#767676",
"#808080",
"#8a8a8a",
"#949494",
"#9e9e9e",
"#a8a8a8",
"#b2b2b2",
"#bcbcbc",
"#c6c6c6",
"#d0d0d0",
"#dadada",
"#e4e4e4",
"#eeeeee",
};

/* Terminal colors for alternate (light) palette */
static const char *altcolorname[] = {
	/* solarized light */
	"#eee8d5",  /*  0: black    */
	"#dc322f",  /*  1: red      */
	"#859900",  /*  2: green    */
	"#b58900",  /*  3: yellow   */
	"#268bd2",  /*  4: blue     */
	"#d33682",  /*  5: magenta  */
	"#2aa198",  /*  6: cyan     */
	"#073642",  /*  7: white    */
	"#fdf6e3",  /*  8: brblack  */
	"#cb4b16",  /*  9: brred    */
	"#93a1a1",  /* 10: brgreen  */
	"#839496",  /* 11: bryellow */
	"#657b83",  /* 12: brblue   */
	"#6c71c4",  /* 13: brmagenta*/
	"#586e75",  /* 14: brcyan   */
	"#002b36",  /* 15: brwhite  */

/* standard xterm colors */
/* #000000 */
/* #800000 */
/* #008000 */
/* #808000 */
/* #000080 */
/* #800080 */
/* #008080 */
/* #c0c0c0 */
/* #808080 */
/* #ff0000 */
/* #00ff00 */
/* #ffff00 */
/* #0000ff */
/* #ff00ff */
/* #00ffff */
/* #ffffff */
"#000000",
"#00005f",
"#000087",
"#0000af",
"#0000d7",
"#0000ff",
"#005f00",
"#005f5f",
"#005f87",
"#005faf",
"#005fd7",
"#005fff",
"#008700",
"#00875f",
"#008787",
"#0087af",
"#0087d7",
"#0087ff",
"#00af00",
"#00af5f",
"#00af87",
"#00afaf",
"#00afd7",
"#00afff",
"#00d700",
"#00d75f",
"#00d787",
"#00d7af",
"#00d7d7",
"#00d7ff",
"#00ff00",
"#00ff5f",
"#00ff87",
"#00ffaf",
"#00ffd7",
"#00ffff",
"#5f0000",
"#5f005f",
"#5f0087",
"#5f00af",
"#5f00d7",
"#5f00ff",
"#5f5f00",
"#5f5f5f",
"#5f5f87",
"#5f5faf",
"#5f5fd7",
"#5f5fff",
"#5f8700",
"#5f875f",
"#5f8787",
"#5f87af",
"#5f87d7",
"#5f87ff",
"#5faf00",
"#5faf5f",
"#5faf87",
"#5fafaf",
"#5fafd7",
"#5fafff",
"#5fd700",
"#5fd75f",
"#5fd787",
"#5fd7af",
"#5fd7d7",
"#5fd7ff",
"#5fff00",
"#5fff5f",
"#5fff87",
"#5fffaf",
"#5fffd7",
"#5fffff",
"#870000",
"#87005f",
"#870087",
"#8700af",
"#8700d7",
"#8700ff",
"#875f00",
"#875f5f",
"#875f87",
"#875faf",
"#875fd7",
"#875fff",
"#878700",
"#87875f",
"#878787",
"#8787af",
"#8787d7",
"#8787ff",
"#87af00",
"#87af5f",
"#87af87",
"#87afaf",
"#87afd7",
"#87afff",
"#87d700",
"#87d75f",
"#87d787",
"#87d7af",
"#87d7d7",
"#87d7ff",
"#87ff00",
"#87ff5f",
"#87ff87",
"#87ffaf",
"#87ffd7",
"#87ffff",
"#af0000",
"#af005f",
"#af0087",
"#af00af",
"#af00d7",
"#af00ff",
"#af5f00",
"#af5f5f",
"#af5f87",
"#af5faf",
"#af5fd7",
"#af5fff",
"#af8700",
"#af875f",
"#af8787",
"#af87af",
"#af87d7",
"#af87ff",
"#afaf00",
"#afaf5f",
"#afaf87",
"#afafaf",
"#afafd7",
"#afafff",
"#afd700",
"#afd75f",
"#afd787",
"#afd7af",
"#afd7d7",
"#afd7ff",
"#afff00",
"#afff5f",
"#afff87",
"#afffaf",
"#afffd7",
"#afffff",
"#d70000",
"#d7005f",
"#d70087",
"#d700af",
"#d700d7",
"#d700ff",
"#d75f00",
"#d75f5f",
"#d75f87",
"#d75faf",
"#d75fd7",
"#d75fff",
"#d78700",
"#d7875f",
"#d78787",
"#d787af",
"#d787d7",
"#d787ff",
"#d7af00",
"#d7af5f",
"#d7af87",
"#d7afaf",
"#d7afd7",
"#d7afff",
"#d7d700",
"#d7d75f",
"#d7d787",
"#d7d7af",
"#d7d7d7",
"#d7d7ff",
"#d7ff00",
"#d7ff5f",
"#d7ff87",
"#d7ffaf",
"#d7ffd7",
"#d7ffff",
"#ff0000",
"#ff005f",
"#ff0087",
"#ff00af",
"#ff00d7",
"#ff00ff",
"#ff5f00",
"#ff5f5f",
"#ff5f87",
"#ff5faf",
"#ff5fd7",
"#ff5fff",
"#ff8700",
"#ff875f",
"#ff8787",
"#ff87af",
"#ff87d7",
"#ff87ff",
"#ffaf00",
"#ffaf5f",
"#ffaf87",
"#ffafaf",
"#ffafd7",
"#ffafff",
"#ffd700",
"#ffd75f",
"#ffd787",
"#ffd7af",
"#ffd7d7",
"#ffd7ff",
"#ffff00",
"#ffff5f",
"#ffff87",
"#ffffaf",
"#ffffd7",
"#ffffff",
"#080808",
"#121212",
"#1c1c1c",
"#262626",
"#303030",
"#3a3a3a",
"#444444",
"#4e4e4e",
"#585858",
"#626262",
"#6c6c6c",
"#767676",
"#808080",
"#8a8a8a",
"#949494",
"#9e9e9e",
"#a8a8a8",
"#b2b2b2",
"#bcbcbc",
"#c6c6c6",
"#d0d0d0",
"#dadada",
"#e4e4e4",
"#eeeeee",
};


/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 12;
unsigned int defaultbg = 8;
static unsigned int defaultcs = 46;
static unsigned int defaultrcs = 46;

/*
 * Default shape of cursor
 * 2: Block ("█")
 * 4: Underline ("_")
 * 6: Bar ("|")
 * 7: Snowman ("☃")
 */
static unsigned int cursorshape = 2;

/*
 * Default columns and rows numbers
 */

static unsigned int cols = 80;
static unsigned int rows = 24;

/*
 * Default colour and shape of the mouse cursor
 */
static unsigned int mouseshape = XC_xterm;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;

/*
 * Color used to display font attributes when fontconfig selected a font which
 * doesn't match the ones requested.
 */
static unsigned int defaultattr = 11;

/*
 * Internal mouse shortcuts.
 * Beware that overloading Button1 will disable the selection.
 */
static MouseShortcut mshortcuts[] = {
	/* button               mask            string */
	{ Button4,              XK_ANY_MOD,     "\031" },
	{ Button5,              XK_ANY_MOD,     "\005" },
};

/* Internal keyboard shortcuts. */
#define MODKEY Mod1Mask
#define TERMMOD (ControlMask|ShiftMask)

static Shortcut shortcuts[] = {
	/* mask                 keysym          function        argument */
	{ XK_ANY_MOD,           XK_Break,       sendbreak,      {.i =  0} },
	{ ControlMask,          XK_Print,       toggleprinter,  {.i =  0} },
	{ ShiftMask,            XK_Print,       printscreen,    {.i =  0} },
	{ XK_ANY_MOD,           XK_Print,       printsel,       {.i =  0} },
	{ TERMMOD,              XK_Prior,       zoom,           {.f = +1} },
	{ TERMMOD,              XK_Next,        zoom,           {.f = -1} },
	{ TERMMOD,              XK_Home,        zoomreset,      {.f =  0} },
	{ TERMMOD,              XK_C,           clipcopy,       {.i =  0} },
	{ TERMMOD,              XK_V,           clippaste,      {.i =  0} },
	{ TERMMOD,              XK_Y,           selpaste,       {.i =  0} },
	{ ShiftMask,            XK_Insert,      selpaste,       {.i =  0} },
	{ TERMMOD,              XK_Num_Lock,    numlock,        {.i =  0} },
	{ ControlMask,          XK_u,           unicodemode,    {.i =  0} },
};

/*
 * Special keys (change & recompile st.info accordingly)
 *
 * Mask value:
 * * Use XK_ANY_MOD to match the key no matter modifiers state
 * * Use XK_NO_MOD to match the key alone (no modifiers)
 * appkey value:
 * * 0: no value
 * * > 0: keypad application mode enabled
 * *   = 2: term.numlock = 1
 * * < 0: keypad application mode disabled
 * appcursor value:
 * * 0: no value
 * * > 0: cursor application mode enabled
 * * < 0: cursor application mode disabled
 * crlf value
 * * 0: no value
 * * > 0: crlf mode is enabled
 * * < 0: crlf mode is disabled
 *
 * Be careful with the order of the definitions because st searches in
 * this table sequentially, so any XK_ANY_MOD must be in the last
 * position for a key.
 */

/*
 * If you want keys other than the X11 function keys (0xFD00 - 0xFFFF)
 * to be mapped below, add them to this array.
 */
static KeySym mappedkeys[] = { -1 };

/*
 * State bits to ignore when matching key or button events.  By default,
 * numlock (Mod2Mask) and keyboard layout (XK_SWITCH_MOD) are ignored.
 */
static uint ignoremod = Mod2Mask|XK_SWITCH_MOD;

/*
 * Override mouse-select while mask is active (when MODE_MOUSE is set).
 * Note that if you want to use ShiftMask with selmasks, set this to an other
 * modifier, set to 0 to not use it.
 */
static uint forceselmod = ShiftMask;

/*
 * This is the huge key array which defines all compatibility to the Linux
 * world. Please decide about changes wisely.
 */
static Key key[] = {
	/* keysym           mask            string      appkey appcursor */
	{ XK_KP_Home,       ShiftMask,      "\033[2J",       0,   -1},
	{ XK_KP_Home,       ShiftMask,      "\033[1;2H",     0,   +1},
	{ XK_KP_Home,       XK_ANY_MOD,     "\033[H",        0,   -1},
	{ XK_KP_Home,       XK_ANY_MOD,     "\033[1~",       0,   +1},
	{ XK_KP_Up,         XK_ANY_MOD,     "\033Ox",       +1,    0},
	{ XK_KP_Up,         XK_ANY_MOD,     "\033[A",        0,   -1},
	{ XK_KP_Up,         XK_ANY_MOD,     "\033OA",        0,   +1},
	{ XK_KP_Down,       XK_ANY_MOD,     "\033Or",       +1,    0},
	{ XK_KP_Down,       XK_ANY_MOD,     "\033[B",        0,   -1},
	{ XK_KP_Down,       XK_ANY_MOD,     "\033OB",        0,   +1},
	{ XK_KP_Left,       XK_ANY_MOD,     "\033Ot",       +1,    0},
	{ XK_KP_Left,       XK_ANY_MOD,     "\033[D",        0,   -1},
	{ XK_KP_Left,       XK_ANY_MOD,     "\033OD",        0,   +1},
	{ XK_KP_Right,      XK_ANY_MOD,     "\033Ov",       +1,    0},
	{ XK_KP_Right,      XK_ANY_MOD,     "\033[C",        0,   -1},
	{ XK_KP_Right,      XK_ANY_MOD,     "\033OC",        0,   +1},
	{ XK_KP_Prior,      ShiftMask,      "\033[5;2~",     0,    0},
	{ XK_KP_Prior,      XK_ANY_MOD,     "\033[5~",       0,    0},
	{ XK_KP_Begin,      XK_ANY_MOD,     "\033[E",        0,    0},
	{ XK_KP_End,        ControlMask,    "\033[J",       -1,    0},
	{ XK_KP_End,        ControlMask,    "\033[1;5F",    +1,    0},
	{ XK_KP_End,        ShiftMask,      "\033[K",       -1,    0},
	{ XK_KP_End,        ShiftMask,      "\033[1;2F",    +1,    0},
	{ XK_KP_End,        XK_ANY_MOD,     "\033[4~",       0,    0},
	{ XK_KP_Next,       ShiftMask,      "\033[6;2~",     0,    0},
	{ XK_KP_Next,       XK_ANY_MOD,     "\033[6~",       0,    0},
	{ XK_KP_Insert,     ShiftMask,      "\033[2;2~",    +1,    0},
	{ XK_KP_Insert,     ShiftMask,      "\033[4l",      -1,    0},
	{ XK_KP_Insert,     ControlMask,    "\033[L",       -1,    0},
	{ XK_KP_Insert,     ControlMask,    "\033[2;5~",    +1,    0},
	{ XK_KP_Insert,     XK_ANY_MOD,     "\033[4h",      -1,    0},
	{ XK_KP_Insert,     XK_ANY_MOD,     "\033[2~",      +1,    0},
	{ XK_KP_Delete,     ControlMask,    "\033[M",       -1,    0},
	{ XK_KP_Delete,     ControlMask,    "\033[3;5~",    +1,    0},
	{ XK_KP_Delete,     ShiftMask,      "\033[2K",      -1,    0},
	{ XK_KP_Delete,     ShiftMask,      "\033[3;2~",    +1,    0},
	{ XK_KP_Delete,     XK_ANY_MOD,     "\033[P",       -1,    0},
	{ XK_KP_Delete,     XK_ANY_MOD,     "\033[3~",      +1,    0},
	{ XK_KP_Multiply,   XK_ANY_MOD,     "\033Oj",       +2,    0},
	{ XK_KP_Add,        XK_ANY_MOD,     "\033Ok",       +2,    0},
	{ XK_KP_Enter,      XK_ANY_MOD,     "\033OM",       +2,    0},
	{ XK_KP_Enter,      XK_ANY_MOD,     "\r",           -1,    0},
	{ XK_KP_Subtract,   XK_ANY_MOD,     "\033Om",       +2,    0},
	{ XK_KP_Decimal,    XK_ANY_MOD,     "\033On",       +2,    0},
	{ XK_KP_Divide,     XK_ANY_MOD,     "\033Oo",       +2,    0},
	{ XK_KP_0,          XK_ANY_MOD,     "\033Op",       +2,    0},
	{ XK_KP_1,          XK_ANY_MOD,     "\033Oq",       +2,    0},
	{ XK_KP_2,          XK_ANY_MOD,     "\033Or",       +2,    0},
	{ XK_KP_3,          XK_ANY_MOD,     "\033Os",       +2,    0},
	{ XK_KP_4,          XK_ANY_MOD,     "\033Ot",       +2,    0},
	{ XK_KP_5,          XK_ANY_MOD,     "\033Ou",       +2,    0},
	{ XK_KP_6,          XK_ANY_MOD,     "\033Ov",       +2,    0},
	{ XK_KP_7,          XK_ANY_MOD,     "\033Ow",       +2,    0},
	{ XK_KP_8,          XK_ANY_MOD,     "\033Ox",       +2,    0},
	{ XK_KP_9,          XK_ANY_MOD,     "\033Oy",       +2,    0},
	{ XK_Up,            ShiftMask,      "\033[1;2A",     0,    0},
	{ XK_Up,            Mod1Mask,       "\033[1;3A",     0,    0},
	{ XK_Up,         ShiftMask|Mod1Mask,"\033[1;4A",     0,    0},
	{ XK_Up,            ControlMask,    "\033[1;5A",     0,    0},
	{ XK_Up,      ShiftMask|ControlMask,"\033[1;6A",     0,    0},
	{ XK_Up,       ControlMask|Mod1Mask,"\033[1;7A",     0,    0},
	{ XK_Up,ShiftMask|ControlMask|Mod1Mask,"\033[1;8A",  0,    0},
	{ XK_Up,            XK_ANY_MOD,     "\033[A",        0,   -1},
	{ XK_Up,            XK_ANY_MOD,     "\033OA",        0,   +1},
	{ XK_Down,          ShiftMask,      "\033[1;2B",     0,    0},
	{ XK_Down,          Mod1Mask,       "\033[1;3B",     0,    0},
	{ XK_Down,       ShiftMask|Mod1Mask,"\033[1;4B",     0,    0},
	{ XK_Down,          ControlMask,    "\033[1;5B",     0,    0},
	{ XK_Down,    ShiftMask|ControlMask,"\033[1;6B",     0,    0},
	{ XK_Down,     ControlMask|Mod1Mask,"\033[1;7B",     0,    0},
	{ XK_Down,ShiftMask|ControlMask|Mod1Mask,"\033[1;8B",0,    0},
	{ XK_Down,          XK_ANY_MOD,     "\033[B",        0,   -1},
	{ XK_Down,          XK_ANY_MOD,     "\033OB",        0,   +1},
	{ XK_Left,          ShiftMask,      "\033[1;2D",     0,    0},
	{ XK_Left,          Mod1Mask,       "\033[1;3D",     0,    0},
	{ XK_Left,       ShiftMask|Mod1Mask,"\033[1;4D",     0,    0},
	{ XK_Left,          ControlMask,    "\033[1;5D",     0,    0},
	{ XK_Left,    ShiftMask|ControlMask,"\033[1;6D",     0,    0},
	{ XK_Left,     ControlMask|Mod1Mask,"\033[1;7D",     0,    0},
	{ XK_Left,ShiftMask|ControlMask|Mod1Mask,"\033[1;8D",0,    0},
	{ XK_Left,          XK_ANY_MOD,     "\033[D",        0,   -1},
	{ XK_Left,          XK_ANY_MOD,     "\033OD",        0,   +1},
	{ XK_Right,         ShiftMask,      "\033[1;2C",     0,    0},
	{ XK_Right,         Mod1Mask,       "\033[1;3C",     0,    0},
	{ XK_Right,      ShiftMask|Mod1Mask,"\033[1;4C",     0,    0},
	{ XK_Right,         ControlMask,    "\033[1;5C",     0,    0},
	{ XK_Right,   ShiftMask|ControlMask,"\033[1;6C",     0,    0},
	{ XK_Right,    ControlMask|Mod1Mask,"\033[1;7C",     0,    0},
	{ XK_Right,ShiftMask|ControlMask|Mod1Mask,"\033[1;8C",0,   0},
	{ XK_Right,         XK_ANY_MOD,     "\033[C",        0,   -1},
	{ XK_Right,         XK_ANY_MOD,     "\033OC",        0,   +1},
	{ XK_ISO_Left_Tab,  ShiftMask,      "\033[Z",        0,    0},
	{ XK_Return,        Mod1Mask,       "\033\r",        0,    0},
	{ XK_Return,        XK_ANY_MOD,     "\r",            0,    0},
	{ XK_Insert,        ShiftMask,      "\033[4l",      -1,    0},
	{ XK_Insert,        ShiftMask,      "\033[2;2~",    +1,    0},
	{ XK_Insert,        ControlMask,    "\033[L",       -1,    0},
	{ XK_Insert,        ControlMask,    "\033[2;5~",    +1,    0},
	{ XK_Insert,        XK_ANY_MOD,     "\033[4h",      -1,    0},
	{ XK_Insert,        XK_ANY_MOD,     "\033[2~",      +1,    0},
	{ XK_Delete,        ControlMask,    "\033[M",       -1,    0},
	{ XK_Delete,        ControlMask,    "\033[3;5~",    +1,    0},
	{ XK_Delete,        ShiftMask,      "\033[2K",      -1,    0},
	{ XK_Delete,        ShiftMask,      "\033[3;2~",    +1,    0},
	{ XK_Delete,        XK_ANY_MOD,     "\033[P",       -1,    0},
	{ XK_Delete,        XK_ANY_MOD,     "\033[3~",      +1,    0},
	{ XK_BackSpace,     XK_NO_MOD,      "\177",          0,    0},
	{ XK_BackSpace,     Mod1Mask,       "\033\177",      0,    0},
	{ XK_Home,          ShiftMask,      "\033[2J",       0,   -1},
	{ XK_Home,          ShiftMask,      "\033[1;2H",     0,   +1},
	{ XK_Home,          XK_ANY_MOD,     "\033[H",        0,   -1},
	{ XK_Home,          XK_ANY_MOD,     "\033[1~",       0,   +1},
	{ XK_End,           ControlMask,    "\033[J",       -1,    0},
	{ XK_End,           ControlMask,    "\033[1;5F",    +1,    0},
	{ XK_End,           ShiftMask,      "\033[K",       -1,    0},
	{ XK_End,           ShiftMask,      "\033[1;2F",    +1,    0},
	{ XK_End,           XK_ANY_MOD,     "\033[4~",       0,    0},
	{ XK_Prior,         ControlMask,    "\033[5;5~",     0,    0},
	{ XK_Prior,         ShiftMask,      "\033[5;2~",     0,    0},
	{ XK_Prior,         XK_ANY_MOD,     "\033[5~",       0,    0},
	{ XK_Next,          ControlMask,    "\033[6;5~",     0,    0},
	{ XK_Next,          ShiftMask,      "\033[6;2~",     0,    0},
	{ XK_Next,          XK_ANY_MOD,     "\033[6~",       0,    0},
	{ XK_F1,            XK_NO_MOD,      "\033OP" ,       0,    0},
	{ XK_F1, /* F13 */  ShiftMask,      "\033[1;2P",     0,    0},
	{ XK_F1, /* F25 */  ControlMask,    "\033[1;5P",     0,    0},
	{ XK_F1, /* F37 */  Mod4Mask,       "\033[1;6P",     0,    0},
	{ XK_F1, /* F49 */  Mod1Mask,       "\033[1;3P",     0,    0},
	{ XK_F1, /* F61 */  Mod3Mask,       "\033[1;4P",     0,    0},
	{ XK_F2,            XK_NO_MOD,      "\033OQ" ,       0,    0},
	{ XK_F2, /* F14 */  ShiftMask,      "\033[1;2Q",     0,    0},
	{ XK_F2, /* F26 */  ControlMask,    "\033[1;5Q",     0,    0},
	{ XK_F2, /* F38 */  Mod4Mask,       "\033[1;6Q",     0,    0},
	{ XK_F2, /* F50 */  Mod1Mask,       "\033[1;3Q",     0,    0},
	{ XK_F2, /* F62 */  Mod3Mask,       "\033[1;4Q",     0,    0},
	{ XK_F3,            XK_NO_MOD,      "\033OR" ,       0,    0},
	{ XK_F3, /* F15 */  ShiftMask,      "\033[1;2R",     0,    0},
	{ XK_F3, /* F27 */  ControlMask,    "\033[1;5R",     0,    0},
	{ XK_F3, /* F39 */  Mod4Mask,       "\033[1;6R",     0,    0},
	{ XK_F3, /* F51 */  Mod1Mask,       "\033[1;3R",     0,    0},
	{ XK_F3, /* F63 */  Mod3Mask,       "\033[1;4R",     0,    0},
	{ XK_F4,            XK_NO_MOD,      "\033OS" ,       0,    0},
	{ XK_F4, /* F16 */  ShiftMask,      "\033[1;2S",     0,    0},
	{ XK_F4, /* F28 */  ControlMask,    "\033[1;5S",     0,    0},
	{ XK_F4, /* F40 */  Mod4Mask,       "\033[1;6S",     0,    0},
	{ XK_F4, /* F52 */  Mod1Mask,       "\033[1;3S",     0,    0},
	{ XK_F5,            XK_NO_MOD,      "\033[15~",      0,    0},
	{ XK_F5, /* F17 */  ShiftMask,      "\033[15;2~",    0,    0},
	{ XK_F5, /* F29 */  ControlMask,    "\033[15;5~",    0,    0},
	{ XK_F5, /* F41 */  Mod4Mask,       "\033[15;6~",    0,    0},
	{ XK_F5, /* F53 */  Mod1Mask,       "\033[15;3~",    0,    0},
	{ XK_F6,            XK_NO_MOD,      "\033[17~",      0,    0},
	{ XK_F6, /* F18 */  ShiftMask,      "\033[17;2~",    0,    0},
	{ XK_F6, /* F30 */  ControlMask,    "\033[17;5~",    0,    0},
	{ XK_F6, /* F42 */  Mod4Mask,       "\033[17;6~",    0,    0},
	{ XK_F6, /* F54 */  Mod1Mask,       "\033[17;3~",    0,    0},
	{ XK_F7,            XK_NO_MOD,      "\033[18~",      0,    0},
	{ XK_F7, /* F19 */  ShiftMask,      "\033[18;2~",    0,    0},
	{ XK_F7, /* F31 */  ControlMask,    "\033[18;5~",    0,    0},
	{ XK_F7, /* F43 */  Mod4Mask,       "\033[18;6~",    0,    0},
	{ XK_F7, /* F55 */  Mod1Mask,       "\033[18;3~",    0,    0},
	{ XK_F8,            XK_NO_MOD,      "\033[19~",      0,    0},
	{ XK_F8, /* F20 */  ShiftMask,      "\033[19;2~",    0,    0},
	{ XK_F8, /* F32 */  ControlMask,    "\033[19;5~",    0,    0},
	{ XK_F8, /* F44 */  Mod4Mask,       "\033[19;6~",    0,    0},
	{ XK_F8, /* F56 */  Mod1Mask,       "\033[19;3~",    0,    0},
	{ XK_F9,            XK_NO_MOD,      "\033[20~",      0,    0},
	{ XK_F9, /* F21 */  ShiftMask,      "\033[20;2~",    0,    0},
	{ XK_F9, /* F33 */  ControlMask,    "\033[20;5~",    0,    0},
	{ XK_F9, /* F45 */  Mod4Mask,       "\033[20;6~",    0,    0},
	{ XK_F9, /* F57 */  Mod1Mask,       "\033[20;3~",    0,    0},
	{ XK_F10,           XK_NO_MOD,      "\033[21~",      0,    0},
	{ XK_F10, /* F22 */ ShiftMask,      "\033[21;2~",    0,    0},
	{ XK_F10, /* F34 */ ControlMask,    "\033[21;5~",    0,    0},
	{ XK_F10, /* F46 */ Mod4Mask,       "\033[21;6~",    0,    0},
	{ XK_F10, /* F58 */ Mod1Mask,       "\033[21;3~",    0,    0},
	{ XK_F11,           XK_NO_MOD,      "\033[23~",      0,    0},
	{ XK_F11, /* F23 */ ShiftMask,      "\033[23;2~",    0,    0},
	{ XK_F11, /* F35 */ ControlMask,    "\033[23;5~",    0,    0},
	{ XK_F11, /* F47 */ Mod4Mask,       "\033[23;6~",    0,    0},
	{ XK_F11, /* F59 */ Mod1Mask,       "\033[23;3~",    0,    0},
	{ XK_F12,           XK_NO_MOD,      "\033[24~",      0,    0},
	{ XK_F12, /* F24 */ ShiftMask,      "\033[24;2~",    0,    0},
	{ XK_F12, /* F36 */ ControlMask,    "\033[24;5~",    0,    0},
	{ XK_F12, /* F48 */ Mod4Mask,       "\033[24;6~",    0,    0},
	{ XK_F12, /* F60 */ Mod1Mask,       "\033[24;3~",    0,    0},
	{ XK_F13,           XK_NO_MOD,      "\033[1;2P",     0,    0},
	{ XK_F14,           XK_NO_MOD,      "\033[1;2Q",     0,    0},
	{ XK_F15,           XK_NO_MOD,      "\033[1;2R",     0,    0},
	{ XK_F16,           XK_NO_MOD,      "\033[1;2S",     0,    0},
	{ XK_F17,           XK_NO_MOD,      "\033[15;2~",    0,    0},
	{ XK_F18,           XK_NO_MOD,      "\033[17;2~",    0,    0},
	{ XK_F19,           XK_NO_MOD,      "\033[18;2~",    0,    0},
	{ XK_F20,           XK_NO_MOD,      "\033[19;2~",    0,    0},
	{ XK_F21,           XK_NO_MOD,      "\033[20;2~",    0,    0},
	{ XK_F22,           XK_NO_MOD,      "\033[21;2~",    0,    0},
	{ XK_F23,           XK_NO_MOD,      "\033[23;2~",    0,    0},
	{ XK_F24,           XK_NO_MOD,      "\033[24;2~",    0,    0},
	{ XK_F25,           XK_NO_MOD,      "\033[1;5P",     0,    0},
	{ XK_F26,           XK_NO_MOD,      "\033[1;5Q",     0,    0},
	{ XK_F27,           XK_NO_MOD,      "\033[1;5R",     0,    0},
	{ XK_F28,           XK_NO_MOD,      "\033[1;5S",     0,    0},
	{ XK_F29,           XK_NO_MOD,      "\033[15;5~",    0,    0},
	{ XK_F30,           XK_NO_MOD,      "\033[17;5~",    0,    0},
	{ XK_F31,           XK_NO_MOD,      "\033[18;5~",    0,    0},
	{ XK_F32,           XK_NO_MOD,      "\033[19;5~",    0,    0},
	{ XK_F33,           XK_NO_MOD,      "\033[20;5~",    0,    0},
	{ XK_F34,           XK_NO_MOD,      "\033[21;5~",    0,    0},
	{ XK_F35,           XK_NO_MOD,      "\033[23;5~",    0,    0},
};

/*
 * Selection types' masks.
 * Use the same masks as usual.
 * Button1Mask is always unset, to make masks match between ButtonPress.
 * ButtonRelease and MotionNotify.
 * If no match is found, regular selection is used.
 */
static uint selmasks[] = {
	[SEL_RECTANGULAR] = Mod1Mask,
};

/*
 * Printable characters in ASCII, used to estimate the advance width
 * of single wide characters.
 */
static char ascii_printable[] =
	" !\"#$%&'()*+,-./0123456789:;<=>?"
	"@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
	"`abcdefghijklmnopqrstuvwxyz{|}~";
