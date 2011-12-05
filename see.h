#ifndef SEE_H
#define SEE_H

#include <QList>

struct flag_t
{
    double x;
    double y;
}
gl={-52.5,0},
gr={+52.5,0},
fc={0.0,0.0},
flt={-52.5,-34},
flb={-52.5,+34},
fct={0,-34},
fcb={0,+34},
frt={+52.5,-34},
frb={+52.5,+34},
fplt,
fplc,
fplb,
fprt,
fprc,
fprb,
fglt,
fglb,
fgrt,
fgrb,
fl0,
fr0,
ft0,
fb0,
ftl10,
ftl20,
ftl30,
ftl40,
ftl50,
ftr10,
ftr20,
ftr30,
ftr40,
ftr50,
fbl10,
fbl20,
fbl30,
fbl40,
fbl50,
fbr10,
fbr20,
fbr30,
fbr40,
fbr50,
flt10,
flt20,
flt30,
flb10,
flb20,
flb30,
frt10,
frt20,
frt30,
frb10,
frb20,
frb30,
ll,
lr,
lt,
lb;

struct player_t1
{
    char* teamName;
    unsigned short uniform;
    player_t1():
        teamName(new char[10]),
        uniform(0)
    {}
};

struct see_t6
{
    player_t1 player;
    double distance;
    double direction;
    double distChange;
    double dirChange;
    double bodyFacingDir;
    double headFacingDir;
    see_t6():
        player(player_t1()),
        distance(0),
        direction(0),
        distChange(0),
        dirChange(0),
        bodyFacingDir(0),
        headFacingDir(0)
    {}
};

struct see_t4
{
    double distance;
    double direction;
    double distChange;
    double dirChange;
    see_t4():
        distance(0),
        direction(0),
        distChange(0),
        dirChange(0)
    {}
};

struct see_t2
{
    double distance;
    double direction;
    see_t2():
        distance(0),
        direction(0)
    {}
};

struct see
{
};

#endif // SEE_H
