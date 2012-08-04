#ifndef SENSE_BODY_H
#define SENSE_BODY_H

#include "../geometry/types.h"


struct t_view_mode
{
    enum view_mode_quality {high,low};
    enum view_mode_width {narrow,normal_w,wide};

    view_mode_quality quality;
    view_mode_width width;
};

struct t_stamina
{
    double stamina;
    double effort;
    double capacity;
    t_stamina(): stamina(0),effort(0),capacity(0){}
};

struct t_arm
{
    int movable;
    Point target;
    int expires;
    int count;
    t_arm()
        :movable(0),target(Point(0.0,0.0)),expires(0),count(0){}
};

struct t_focus
{
    enum focus_type {none=0,l,r};
    focus_type type;
    int unum;
    int count;
    t_focus():type(none),unum(0),count(0){}
};

struct t_tackle
{
    int expires;
    int count;
    t_tackle():expires(0),count(0){}
};

struct t_collition
{
    enum collition_type{none=0,ball=1,player=2,post=4};
    int type;
    t_collition():type(none){}
};

struct t_foul
{
    enum card_type{none,yellow};
    int charged;
    card_type card;
    t_foul()
        :charged(0),card(none){}
};

struct t_sense_body
{
    int time;
    t_view_mode view_mode;
    t_stamina stamina;
    Point speed;
    int head_angle;
    int kick;
    int dash;
    int turn;
    int say;
    int turn_neck;
    int catch_;
    int move;
    int change_view;
    t_arm arm;
    t_focus focus;
    t_tackle tackle;
    t_collition collition;
    t_foul foul;
};

#endif // SENSE_BODY_H
