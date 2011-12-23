#ifndef PLAYER_PARAM_H
#define PLAYER_PARAM_H

#include <QList>

class player_type
{
public:
    player_type(double _catchable_area_l_stretch,
                double _dash_power_rate,
                double _effort_max,
                double _effort_min,
                double _extra_stamina,
                double _foul_detect_probability,
                double _id,
                double _inertia_moment,
                double _kick_power_rate,
                double _kick_rand,
                double _kickable_margin,
                double _player_decay,
                double _player_size,
                double _player_speed_max,
                double _stamina_inc_max);
    double catchable_area_l_stretch;
    double dash_power_rate;
    double effort_max;
    double effort_min;
    double extra_stamina;
    double foul_detect_probability;
    double id;
    double inertia_moment;
    double kick_power_rate;
    double kick_rand;
    double kickable_margin;
    double player_decay;
    double player_size;
    double player_speed_max;
    double stamina_inc_max;
    static QList<player_type*> players;
};

#endif // PLAYER_PARAM_H
