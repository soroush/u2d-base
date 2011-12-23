#include "player_type.h"

QList<player_type*> player_type::players;

player_type::player_type(double _catchable_area_l_stretch,
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
                         double _stamina_inc_max):
    catchable_area_l_stretch(_catchable_area_l_stretch),
    dash_power_rate(_dash_power_rate),
    effort_max(_effort_max),
    effort_min(_effort_min),
    extra_stamina(_extra_stamina),
    foul_detect_probability(_foul_detect_probability),
    id(_id),
    inertia_moment(_inertia_moment),
    kick_power_rate(_kick_power_rate),
    kick_rand(_kick_rand),
    kickable_margin(_kickable_margin),
    player_decay(_player_decay),
    player_size(_player_size),
    player_speed_max(_player_speed_max),
    stamina_inc_max(_stamina_inc_max)
{
}
