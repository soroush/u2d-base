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

#ifndef U2D_SERVER_PARAM_HPP
#define U2D_SERVER_PARAM_HPP

#include <string>
#include <ostream>

namespace u2d {
struct server_param_t {
    float audio_cut_dist;
    bool auto_mode;
    float back_dash_rate;
    bool back_passes;
    float ball_accel_max;
    float ball_decay;
    float ball_rand;
    float ball_size;
    float ball_speed_max;
    float ball_stuck_area;
    float ball_weight;
    int catch_ban_cycle;
    float catch_probability;
    float catchable_area_l;
    float catchable_area_w;
    float ckick_margin;
    int clang_advice_win;
    int clang_del_win;
    int clang_define_win;
    int clang_info_win;
    int clang_mess_delay;
    int clang_mess_per_cycle;
    int clang_meta_win;
    int clang_rule_win;
    int clang_win_size;
    bool coach;
    int coach_port;
    bool coach_w_referee;
    int connect_wait;
    float control_radius;
    float dash_angle_step;
    float dash_power_rate;
    int drop_ball_time;
    float effort_dec;
    float effort_dec_thr;
    float effort_inc;
    float effort_inc_thr;
    float effort_init;
    float effort_min;
    int extra_half_time;
    float extra_stamina;
    bool forbid_kick_off_offside;
    int foul_cycles;
    float foul_detect_probability;
    float foul_exponent;
    bool free_kick_faults;
    unsigned int freeform_send_period;
    unsigned int freeform_wait_period;
    int fullstate_l;
    int fullstate_r;
    int game_log_compression;
    int game_log_dated;
    std::string game_log_dir;
    bool game_log_fixed;
    std::string game_log_fixed_name;
    int game_log_version;
    bool game_logging;
    int game_over_wait;
    float goal_width;
    int goalie_max_moves;
    bool golden_goal;
    int half_time;
    unsigned int hear_decay;
    unsigned int hear_inc;
    unsigned int hear_max;
    float inertia_moment;
    bool keepaway;
    float keepaway_length;
    bool keepaway_log_dated;
    std::string keepaway_log_dir;
    bool keepaway_log_fixed;
    std::string keepaway_log_fixed_name;
    bool keepaway_logging;
    int keepaway_start;
    float keepaway_width;
    int kick_off_wait;
    float kick_power_rate;
    float kick_rand;
    float kick_rand_factor_l;
    float kick_rand_factor_r;
    float kickable_margin;
    std::string landmark_file;
    std::string log_date_format;
    int log_times;
    float max_back_tackle_power;
    float max_dash_angle;
    float max_dash_power;
    int max_goal_kicks;
    float max_tackle_power;
    float maxmoment;
    float maxneckang;
    float maxneckmoment;
    float maxpower;
    float min_dash_angle;
    float min_dash_power;
    float minmoment;
    float minneckang;
    float minneckmoment;
    float minpower;
    int nr_extra_halfs;
    int nr_normal_halfs;
    float offside_active_area_size;
    float offside_kick_margin;
    int olcoach_port;
    bool old_coach_hear;
    bool pen_allow_mult_kicks;
    int pen_before_setup_wait;
    bool pen_coach_moves_players;
    float pen_dist_x;
    int pen_max_extra_kicks;
    int pen_max_goalie_dist_x;
    int pen_nr_kicks;
    bool pen_random_winner;
    int pen_ready_wait;
    int pen_setup_wait;
    int pen_taken_wait;
    bool penalty_shoot_outs;
    float player_accel_max;
    float player_decay;
    float player_rand;
    float player_size;
    float player_speed_max;
    float player_speed_max_min;
    float player_weight;
    int point_to_ban;
    int point_to_duration;
    int port;
    float prand_factor_l;
    float prand_factor_r;
    bool profile;
    bool proper_goal_kicks;
    float quantize_step;
    float quantize_step_l; //?
    bool record_messages;
    float recover_dec;
    float recover_dec_thr;
    float recover_init;
    float recover_min;
    int recv_step;
    float red_card_probability;
    int say_coach_cnt_max;
    int say_coach_msg_size;
    int say_msg_size;
    bool send_comms;
    int send_step;
    int send_vi_step;
    int sense_body_step;
    float side_dash_rate;
    int simulator_step;
    int slow_down_factor;
    float slowness_on_top_for_left_team;
    float slowness_on_top_for_right_team;
    float stamina_capacity;
    float stamina_inc_max;
    float stamina_max;
    int start_goal_l;
    int start_goal_r;
    float stopped_ball_vel;
    unsigned int synch_micro_sleep;
    bool synch_mode;
    int synch_offset;
    int synch_see_offset;
    float tackle_back_dist;
    unsigned int tackle_cycles;
    float tackle_dist;
    float tackle_exponent;
    float tackle_power_rate;
    float tackle_rand_factor;
    float tackle_width;
    bool team_actuator_noise;
    std::string team_l_start;
    std::string team_r_start;
    int text_log_compression;
    int text_log_dated;
    std::string text_log_dir;
    int text_log_fixed;
    std::string text_log_fixed_name;
    bool text_logging;
    bool use_offside;
    bool verbose;
    float visible_angle;
    float visible_distance;
    float wind_ang;
    float wind_dir;
    float wind_force;
    bool wind_none;
    float wind_rand;
    bool wind_random;
};
}

std::ostream& operator<<(std::ostream&, const u2d::server_param_t&);

#endif // U2d_SERVER_PARAM_HPP
