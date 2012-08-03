#ifndef PLAYER_TYPE_H
#define PLAYER_TYPE_H

struct t_player_type
{
    unsigned short int id;
    double player_speed_max;
    double stamina_inc_max;
    double player_decay;
    double inertia_moment;
    double dash_power_rate;
    double player_size;
    double kickable_margin;
    double kick_rand;
    double extra_stamina;
    double effort_max;
    double effort_min;
    double kick_power_rate;
    double foul_detect_probability;
    double catchable_area_l_stretch;
};


#endif // PLAYER_TYPE_H
