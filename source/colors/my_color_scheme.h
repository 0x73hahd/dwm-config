static const char col_gray1[]       = "#081F2F";
static const char col_gray3[]       = "#FF8888";
static const char col_gray4[]       = "#8FBBC0";
static const char col_gray2[]       = "#FF5A8E";
static const char col_cyan[]        = "#081F2F";
static const char *colors[][3]      = {

    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_cyan },
    [SchemeSel]  = { col_gray4, col_cyan,  col_gray2  },
    [SchemeTitle]  = { col_gray4, col_cyan,  col_cyan  },
};
