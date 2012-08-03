#ifndef PLAYER_PARAM_H
#define PLAYER_PARAM_H

struct t_player_param
{
    bool   allow_mult_default_type;
    double catchable_area_l_stretch_max;
    double catchable_area_l_stretch_min;
    double dash_power_rate_delta_max;
    double dash_power_rate_delta_min;
    double effort_max_delta_factor;
    double effort_min_delta_factor;
    double extra_stamina_delta_max;
    double extra_stamina_delta_min;
    double foul_detect_probability_delta_factor;
    double inertia_moment_delta_factor;
    double kick_power_rate_delta_max;
    double kick_power_rate_delta_min;
    double kick_rand_delta_factor;
    double kickable_margin_delta_max;
    double kickable_margin_delta_min;
    double new_dash_power_rate_delta_max;
    double new_dash_power_rate_delta_min;
    double new_stamina_inc_max_delta_factor;
    double player_decay_delta_max;
    double player_decay_delta_min;
    double player_size_delta_factor;
    double player_speed_max_delta_max;
    double player_speed_max_delta_min;
    int    player_types;
    int    pt_max;
    double random_seed;
    double stamina_inc_max_delta_factor;
    int    subs_max;
};

#endif // PLAYER_PARAM_H
