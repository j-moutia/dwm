/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Terminus:size=8" };
static const char dmenufont[]       = "Terminus:size=8";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Brave",    NULL,       NULL,       1,       	    0,           -1 },
	{ "st",	      NULL,       NULL,       2,	    0,		 -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/zsh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
    /* modifier                     key        	        function        argument */
    { MODKEY|ShiftMask,             XK_Escape, 	        spawn,          SHCMD("dm_prompt \"Exit dwm?\" \"killall xinit\"") },
    
    TAGKEYS(                        XK_1,                      	        0)
    TAGKEYS(                        XK_2,                      	        1)
    TAGKEYS(                        XK_3,                      	        2)
    TAGKEYS(                        XK_4,                      	        3)
    TAGKEYS(                        XK_5,                      	        4)
    TAGKEYS(                        XK_6,                      	        5)
    TAGKEYS(                        XK_7,                      	        6)
    TAGKEYS(                        XK_8,                      	        7)
    TAGKEYS(                        XK_9,                      	        8)
    { MODKEY,                       XK_0,      	        view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      	        tag,            {.ui = ~0 } },

	{ MODKEY|ShiftMask,		        XK_BackSpace,	    spawn,	   	    SHCMD("dm_prompt \"Reboot computer?\" \"reboot\"") },
    { MODKEY,                       XK_Tab,             view,           {0} },

    { MODKEY,                       XK_q,               killclient,     {0} },
    //{ MODKEY|ShiftMask,             XK_q,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_w,               killclient,     {0} },
    { MODKEY|ShiftMask,             XK_w,               spawn,          SHCMD("$BROWSER") },
    //{ MODKEY,                       XK_e,               killclient,     {0} },
    //{ MODKEY|ShiftMask,             XK_e,               spawn,          SHCMD("") },
    { MODKEY,                       XK_r,               spawn,          SHCMD("st -e lf") },
    { MODKEY|ShiftMask,             XK_r,               quit,           {1} },
    { MODKEY,                       XK_t,               spawn,          {.v = &layouts[0]} },
    { MODKEY|ShiftMask,             XK_t,               spawn,          {.v = &layouts[1]} },
    { MODKEY,                       XK_y,               spawn,          {.v = &layouts[2]} },
    //{ MODKEY|ShiftMask,             XK_y,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_u,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_u,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_i,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_i,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_o,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_o,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_p,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_p,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_bracketleft,     spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_bracketleft,     spawn,          SHCMD("") },
    //{ MODKEY,                       XK_bracketright,    spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_bracketright,    spawn,          SHCMD("") },
    //{ MODKEY,                       XK_backslash,       spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_backslash,       spawn,          SHCMD("") },

    //{ MODKEY,                       XK_a,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_a,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_s,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_s,               spawn,          SHCMD("") },
    { MODKEY,                       XK_d,               spawn,          {.v = dmenucmd} },
    //{ MODKEY|ShiftMask,             XK_d,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_f,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_f,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_g,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_g,               spawn,          SHCMD("") },
    { MODKEY,                       XK_h,               setmfact,       {.f = -0.05} },
    //{ MODKEY|ShiftMask,             XK_h,               spawn,          SHCMD("") },
    { MODKEY,                       XK_j,               focusstack,     {.i = +1} },
    { MODKEY|ShiftMask,             XK_j,               incnmaster,     {.i = +1} },
    { MODKEY,                       XK_k,               focusstack,     {.i = -1} },
    { MODKEY|ShiftMask,             XK_k,               incnmaster,     {.i = -1} },
    { MODKEY,                       XK_l,               setmfact,       {.f = +0.05} },
    //{ MODKEY|ShiftMask,             XK_l,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_semicolon,       spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_semicolon,       spawn,          SHCMD("") },
    //{ MODKEY,                       XK_apostrophe,      spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_apostrophe,      spawn,          SHCMD("") },
	{ MODKEY,             		    XK_Return, 	        spawn,          {.v = termcmd } },
    //{ MODKEY|ShiftMask,             XK_Return,          spawn,          SHCMD("") },

    //{ MODKEY,                       XK_z,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_z,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_x,               spawn,          SHCMD("") },
	{ MODKEY|ShiftMask, 		    XK_x,	   	        spawn,	   	    SHCMD("dm_prompt \"Shutdown computer?\" \"shutdown -h now\"") },
    //{ MODKEY,                       XK_c,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_c,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_v,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_v,               spawn,          SHCMD("") },
    { MODKEY,                       XK_b,               togglebar,      {0} },
    //{ MODKEY|ShiftMask,             XK_b,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_n,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_n,               spawn,          SHCMD("") },
    //{ MODKEY,                       XK_m,               spawn,          SHCMD("") },
    //{ MODKEY|ShiftMask,             XK_m,               spawn,          SHCMD("") },
    { MODKEY,                       XK_comma,           focusmon,       {.i = -1} },
    { MODKEY|ShiftMask,             XK_comma,           tagmon,         {.i = -1} },
    { MODKEY,                       XK_period,          focusmon,       {.i = +1} },
    { MODKEY|ShiftMask,             XK_period,          tagmon,         {.i = +1} },
	{ MODKEY,                       XK_space,  	        setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  	        togglefloating, {0} },

	//{ MODKEY,                       XK_F1,  	        spawn,          SHCMD("") },
	{ MODKEY,                       XK_F2,  	        quit,           {1} },
	//{ MODKEY,                       XK_F3,  	        spawn,          SHCMD("") },
	//{ MODKEY,                       XK_F4,  	        spawn,          SHCMD("") },
	//{ MODKEY,                       XK_F5,  	        spawn,          SHCMD("") },
	//{ MODKEY,                       XK_F6,  	        spawn,          SHCMD("") },
	//{ MODKEY,                       XK_F7,  	        spawn,          SHCMD("") },
	{ MODKEY,                       XK_F8,  	        spawn,          SHCMD("toggle_tpad") },
	//{ MODKEY,                       XK_F9,  	        spawn,          SHCMD("") },
	//{ MODKEY,                       XK_F10,  	        spawn,          SHCMD("") },
	//{ MODKEY,                       XK_F11,  	        spawn,          SHCMD("") },
	//{ MODKEY,                       XK_F12,  	        spawn,          SHCMD("") },

	// Special keys
	{ 0, XF86XK_AudioMute,		    spawn,		SHCMD("amixer set Master toggle") },
	{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("amixer set Master 5%+") },
	{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("amixer set Master 5%-") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

