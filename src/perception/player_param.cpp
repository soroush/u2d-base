/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2016 Soroush Rabiei <rabiei@tidm.net>

 U2D is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 See the file COPYING included with this distribution for more
 information.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "player_param.hpp"

std::ostream& operator<<(std::ostream& os, const u2d::player_param_t& param) {
    os << "Player Parameters: " << '\n';
    os << "    allow_mult_default_type: " << param.allow_mult_default_type<< '\n';
    os << "    catchable_area_l_stretch_max: " << param.catchable_area_l_stretch_max<< '\n';
    os << "    catchable_area_l_stretch_min: " << param.catchable_area_l_stretch_min<< '\n';
    os << "    dash_power_rate_delta_max: " << param.dash_power_rate_delta_max<< '\n';
    os << "    dash_power_rate_delta_min: " << param.dash_power_rate_delta_min<< '\n';
    os << "    effort_max_delta_factor: " << param.effort_max_delta_factor<< '\n';
    os << "    effort_min_delta_factor: " << param.effort_min_delta_factor<< '\n';
    os << "    extra_stamina_delta_max: " << param.extra_stamina_delta_max<< '\n';
    os << "    extra_stamina_delta_min: " << param.extra_stamina_delta_min<< '\n';
    os << "    foul_detect_probability_delta_factor: " << param.foul_detect_probability_delta_factor<< '\n';
    os << "    inertia_moment_delta_factor: " << param.inertia_moment_delta_factor<< '\n';
    os << "    kick_power_rate_delta_max: " << param.kick_power_rate_delta_max<< '\n';
    os << "    kick_power_rate_delta_min: " << param.kick_power_rate_delta_min<< '\n';
    os << "    kick_rand_delta_factor: " << param.kick_rand_delta_factor<< '\n';
    os << "    kickable_margin_delta_max: " << param.kickable_margin_delta_max<< '\n';
    os << "    kickable_margin_delta_min: " << param.kickable_margin_delta_min<< '\n';
    os << "    new_dash_power_rate_delta_max: " << param.new_dash_power_rate_delta_max<< '\n';
    os << "    new_dash_power_rate_delta_min: " << param.new_dash_power_rate_delta_min<< '\n';
    os << "    new_stamina_inc_max_delta_factor: " << param.new_stamina_inc_max_delta_factor<< '\n';
    os << "    player_decay_delta_max: " << param.player_decay_delta_max<< '\n';
    os << "    player_decay_delta_min: " << param.player_decay_delta_min<< '\n';
    os << "    player_size_delta_factor: " << param.player_size_delta_factor<< '\n';
    os << "    player_speed_max_delta_max: " << param.player_speed_max_delta_max<< '\n';
    os << "    player_speed_max_delta_min: " << param.player_speed_max_delta_min<< '\n';
    os << "    player_types: " << static_cast<int>(param.player_types) << '\n';
    os << "    pt_max: " << static_cast<int>(param.pt_max) << '\n';
    os << "    random_seed: " << param.random_seed << '\n';
    os << "    stamina_inc_max_delta_factor: " << param.stamina_inc_max_delta_factor<< '\n';
    os << "    subs_max: " << static_cast<int>(param.subs_max)<< std::endl;
    return os;
}
