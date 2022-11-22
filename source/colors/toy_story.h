static const char col_gray1[]       = "#395f8f";
static const char col_gray3[]       = "#ffffff";
static const char col_gray4[]       = "#edac7b";
static const char col_gray2[]       = "#2a4756";
static const char col_cyan[]        = "#395f8f";

static const char tag1[]            = "#191a1b";
static const char tag2[]            = "#5865F2";
static const char tag3[]            = "#FF5500";
static const char tag4[]            = "#FF609A";
static const char tag5[]            = "#842291";
static const char tag6[]            = "#900C3F";
static const char tag7[]            = "#67AFA5";
static const char tag8[]            = "#1DB954";
static const char tag9[]            = "#FFFFFF";

static const char *colors[][3]      = {
    /*                 fg         bg         border   */
    [SchemeNorm]   = { col_gray3, col_gray1, col_cyan },
    [SchemeSel]    = { col_gray4, col_cyan,  col_gray2  },
    [SchemeTitle]  = { col_gray4, col_cyan,  col_cyan  },
};

static const char *tagsel[][2] = {
	{   tag1, col_gray1   },
	{   tag2, col_gray1   },
	{   tag3, col_gray1   },
	{   tag4, col_gray1   },
	{   tag5, col_gray1   },
	{   tag6, col_gray1   },
	{   tag7, col_gray1   },
	{   tag8, col_gray1   },
	{   tag9, col_gray1   },
};
