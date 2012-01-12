#ifndef PLAYER_PARAM_H
#define PLAYER_PARAM_H

class player_param
{
public:
    player_param();
    static bool allow_mult_default_type ;
    static double catchable_area_l_stretch_max ;
    static double catchable_area_l_stretch_min ;
    static double dash_power_rate_delta_max ;
    static double dash_power_rate_delta_min ;
    static double effort_max_delta_factor ;
    static double effort_min_delta_factor ;
    static double extra_stamina_delta_max ;
    static double extra_stamina_delta_min ;
    static double foul_detect_probability_delta_factor ;
    static double inertia_moment_delta_factor ;
    static double kick_power_rate_delta_max ;
    static double kick_power_rate_delta_min ;
    static double kick_rand_delta_factor ;
    static double kickable_margin_delta_max ;
    static double kickable_margin_delta_min ;
    static double new_dash_power_rate_delta_max ;
    static double new_dash_power_rate_delta_min ;
    static double new_stamina_inc_max_delta_factor ;
    static double player_decay_delta_max ;
    static double player_decay_delta_min ;
    static double player_size_delta_factor ;
    static double player_speed_max_delta_max ;
    static double player_speed_max_delta_min ;
    static int player_types ;
    static double pt_max ;
    static long random_seed ;
    static double stamina_inc_max_delta_factor ;
    static int subs_max;
};

#endif // PLAYER_PARAM_H
