#include "layouts.h"
#include "movestack.c"

#define TERMINAL	"alacritty"           // default terminal 

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(CHAIN,KEY,TAG) \
	{ MODKEY,                       CHAIN,    KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           CHAIN,    KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             CHAIN,    KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, CHAIN,    KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char dmenufont[] = "monospace:size=10";
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };

/* brightness control */
static const char *inc_light[] = {"light", "-A", "5"};
static const char *dec_light[] = {"light", "-U", "5"};

/* volume controls */
static const char *increase_vol[]   = { "pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *decrease_vol[] = { "pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mute_vol[] = { "pactl", "set-sink-mute",   "0", "toggle",  NULL };

static const Key keys[] = {
		/* modifier                     chain key   key        function        argument */
		{ MODKEY,                       -1,         XK_p,      spawn,          {.v = dmenucmd } },
		{ MODKEY,                       -1,         XK_t,      spawn,          {.v = termcmd } }, // open default terminal on the current tag
		{ MODKEY|ShiftMask,             -1,         XK_h,      togglebar,      {0} },
		{ MODKEY,                       -1,         XK_j,      focusstack,     {.i = +1 } },
		{ MODKEY,                       -1,         XK_k,      focusstack,     {.i = -1 } },
		{ MODKEY,                       -1,         XK_i,      incnmaster,     {.i = +1 } },
		{ MODKEY,                       -1,         XK_d,      incnmaster,     {.i = -1 } },
	    { ShiftMask,                    -1,         XK_x,      movestack,      {.i = +1 } },
	    { ShiftMask,                    -1,         XK_z,      movestack,      {.i = -1 } },
		{ MODKEY,                       -1,         XK_h,      setmfact,       {.f = -0.05} },
		{ MODKEY,                       -1,         XK_l,      setmfact,       {.f = +0.05} },
		{ MODKEY,                       -1,         XK_Return, zoom,           {0} },
		{ MODKEY,                       -1,         XK_Tab,    view,           {0} },
		{ MODKEY|ShiftMask,             -1,         XK_k,      killclient,     {0} },
		
		{ ControlMask,                  -1,         XK_t,      setlayout,      {.v = &layouts[0]} },
		{ ControlMask,                  -1,         XK_f,      setlayout,      {.v = &layouts[1]} },
		{ ControlMask,                  -1,         XK_m,      setlayout,      {.v = &layouts[2]} },
		{ ControlMask,                  -1,         XK_space,  setlayout,      {0} },
		
		{ MODKEY|ShiftMask,             -1,         XK_space,  togglefloating, {0} },
		{ MODKEY,                       -1,         XK_0,      view,           {.ui = ~0 } },
		{ MODKEY|ShiftMask,             -1,         XK_0,      tag,            {.ui = ~0 } },
		{ MODKEY,                       -1,         XK_comma,  focusmon,       {.i = -1 } },
		{ MODKEY,                       -1,         XK_period, focusmon,       {.i = +1 } },
		{ MODKEY|ShiftMask,             -1,         XK_comma,  tagmon,         {.i = -1 } },
		{ MODKEY|ShiftMask,             -1,         XK_period, tagmon,         {.i = +1 } },

		{ MODKEY,                       XK_a,       XK_t,      spawn,          SHCMD("xdotool key Super_L+9 && alacritty") }, // open alacritty on tag9
		{ MODKEY,                       -1,         XK_r,      spawn,          SHCMD("xdotool key Super_L+6 && atril") },
		{ MODKEY,                       XK_b,       XK_b,      spawn,          SHCMD("xdotool key Super_L+3 && brave") }, // open brave on tag3
		{ MODKEY,                       -1,         XK_d,      spawn,          SHCMD("xdotool key Super_L+2 && discord") }, // open discord on tag2
		{ MODKEY,                       XK_f,       XK_m,      spawn,          SHCMD("xdotool key Super_L+1 && dolphin") }, // open dolphin on tag1
		{ MODKEY,                       -1,         XK_g,      spawn,          SHCMD("xdotool key Super_L+5 && github-desktop") }, // open github-desktop on tag5
	    { MODKEY,                       XK_i,       XK_v,      spawn,          SHCMD("gwenview") },
        { MODKEY,                       XK_j,       XK_b,      spawn,          SHCMD("jetbrains-toolbox") },
		{ MODKEY,                       XK_n,       XK_v,      spawn,          SHCMD(TERMINAL " -e nvim") },
		{ ControlMask|ShiftMask,        -1,         XK_s,      spawn,          SHCMD("spectacle") }, // take a screenshot
		{ MODKEY,                       -1,         XK_s,      spawn,          SHCMD("xdotool key Super_L+8 && brave --app=https://open.spotify.com/collection/tracks") },	// open spotify on tag8 because I love music :D

 
		TAGKEYS(                        -1,         XK_1,                      0)
		TAGKEYS(                        -1,         XK_2,                      1)
		TAGKEYS(                        -1,         XK_3,                      2)
		TAGKEYS(                        -1,         XK_4,                      3)
		TAGKEYS(                        -1,         XK_5,                      4)
		TAGKEYS(                        -1,         XK_6,                      5)
		TAGKEYS(                        -1,         XK_7,                      6)
		TAGKEYS(                        -1,         XK_8,                      7)
		TAGKEYS(                        -1,         XK_9,                      8)
		
		{ MODKEY|ShiftMask,             -1,         XK_x,      quit,           {0} },
	    { MODKEY|ControlMask|ShiftMask, -1,         XK_r,      quit,           {1} },	// restart

		{ 0,                       		-1, 		XF86XK_AudioRaiseVolume, spawn, 	   {.v = increase_vol } },
		{ 0,                       		-1, 		XF86XK_AudioLowerVolume, spawn,        {.v = decrease_vol } },
		{ 0,                       		-1,	        XF86XK_AudioMute, spawn, 			   {.v = mute_vol } },

		{ 0,			                -1,       	XF86XK_MonBrightnessUp,	 spawn,	       {.v = inc_light} },
	    { 0,				            -1,         XF86XK_MonBrightnessDown,spawn,	       {.v = dec_light} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
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
