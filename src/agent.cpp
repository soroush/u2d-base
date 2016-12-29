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

#include "agent.hpp"

u2d::agent::agent(const std::string& team,
                  const std::string& host,
                  uint16_t port):
    _team(team),
    _connection(host,port),
    _parser(_istream,_ostream,_model) {
}

void u2d::agent::set_team_name(const std::string& team) {
    this->_team = team;
}

void u2d::agent::run() {
    std::string init = "(init " + _team + " (version 15))";
    this->_connection.write(init);
    init = _connection.read();
    _istream.str(init);
    _parser.parse();
    while(_model.play_mode != model_t::play_mode_t::time_over ) {
        std::string data = _connection.read();
        _istream.clear();
        _istream.str(data);
        _parser.parse();
        switch(_model.last_input) {
        case model_t::input_t::init:
            break;
        case model_t::input_t::server_param:
            print_server_param();
            break;
        case model_t::input_t::player_param:
            print_player_param();
            break;
        case model_t::input_t::player_type:
            break;
        case model_t::input_t::sense_body:
            break;
        case model_t::input_t::see:
            break;
        case model_t::input_t::hear:
            break;
        case model_t::input_t::error:
            break;
        }
    }
}

void u2d::agent::print_server_param() {
    std::cerr << "play_mode: " << this->_model.play_mode_str() << std::endl;
    std::cerr << "server.audio_cut_dist: " <<_model.server.audio_cut_dist << std::endl;
    std::cerr << "server.auto_mode: " <<_model.server.auto_mode << std::endl;
    std::cerr << "server.back_dash_rate: " <<_model.server.back_dash_rate << std::endl;
    std::cerr << "server.back_passes: " <<_model.server.back_passes << std::endl;
    std::cerr << "server.ball_accel_max: " <<_model.server.ball_accel_max << std::endl;
    std::cerr << "server.ball_decay: " <<_model.server.ball_decay << std::endl;
    std::cerr << "server.ball_rand: " <<_model.server.ball_rand << std::endl;
    std::cerr << "server.ball_size: " <<_model.server.ball_size << std::endl;
    std::cerr << "server.ball_speed_max: " <<_model.server.ball_speed_max << std::endl;
    std::cerr << "server.ball_stuck_area: " <<_model.server.ball_stuck_area << std::endl;
    std::cerr << "server.ball_weight: " <<_model.server.ball_weight << std::endl;
    std::cerr << "server.catch_ban_cycle: " <<_model.server.catch_ban_cycle << std::endl;
    std::cerr << "server.catch_probability: " <<_model.server.catch_probability << std::endl;
    std::cerr << "server.catchable_area_l: " <<_model.server.catchable_area_l << std::endl;
    std::cerr << "server.catchable_area_w: " <<_model.server.catchable_area_w << std::endl;
    std::cerr << "server.ckick_margin: " <<_model.server.ckick_margin << std::endl;
    std::cerr << "server.clang_advice_win: " <<_model.server.clang_advice_win << std::endl;
    std::cerr << "server.clang_define_win: " <<_model.server.clang_define_win << std::endl;
    std::cerr << "server.clang_del_win: " <<_model.server.clang_del_win << std::endl;
    std::cerr << "server.clang_info_win: " <<_model.server.clang_info_win << std::endl;
    std::cerr << "server.clang_mess_delay: " <<_model.server.clang_mess_delay << std::endl;
    std::cerr << "server.clang_mess_per_cycle: " <<_model.server.clang_mess_per_cycle
              << std::endl;
    std::cerr << "server.clang_meta_win: " <<_model.server.clang_meta_win << std::endl;
    std::cerr << "server.clang_rule_win: " <<_model.server.clang_rule_win << std::endl;
    std::cerr << "server.clang_win_size: " <<_model.server.clang_win_size << std::endl;
    std::cerr << "server.coach: " <<_model.server.coach << std::endl;
    std::cerr << "server.coach_port: " <<_model.server.coach_port << std::endl;
    std::cerr << "server.coach_w_referee: " <<_model.server.coach_w_referee << std::endl;
    std::cerr << "server.connect_wait: " <<_model.server.connect_wait << std::endl;
    std::cerr << "server.control_radius: " <<_model.server.control_radius << std::endl;
    std::cerr << "server.dash_angle_step: " <<_model.server.dash_angle_step << std::endl;
    std::cerr << "server.dash_power_rate: " <<_model.server.dash_power_rate << std::endl;
    std::cerr << "server.drop_ball_time: " <<_model.server.drop_ball_time << std::endl;
    std::cerr << "server.effort_dec: " <<_model.server.effort_dec << std::endl;
    std::cerr << "server.effort_dec_thr: " <<_model.server.effort_dec_thr << std::endl;
    std::cerr << "server.effort_inc: " <<_model.server.effort_inc << std::endl;
    std::cerr << "server.effort_inc_thr: " <<_model.server.effort_inc_thr << std::endl;
    std::cerr << "server.effort_init: " <<_model.server.effort_init << std::endl;
    std::cerr << "server.effort_min: " <<_model.server.effort_min << std::endl;
    std::cerr << "server.extra_half_time: " <<_model.server.extra_half_time << std::endl;
    std::cerr << "server.extra_stamina: " <<_model.server.extra_stamina << std::endl;
    std::cerr << "server.forbid_kick_off_offside: " <<_model.server.forbid_kick_off_offside
              << std::endl;
    std::cerr << "server.foul_cycles: " <<_model.server.foul_cycles << std::endl;
    std::cerr << "server.foul_detect_probability: " <<_model.server.foul_detect_probability
              << std::endl;
    std::cerr << "server.foul_exponent: " <<_model.server.foul_exponent << std::endl;
    std::cerr << "server.free_kick_faults: " <<_model.server.free_kick_faults << std::endl;
    std::cerr << "server.freeform_send_period: " <<_model.server.freeform_send_period
              << std::endl;
    std::cerr << "server.freeform_wait_period: " <<_model.server.freeform_wait_period
              << std::endl;
    std::cerr << "server.fullstate_l: " <<_model.server.fullstate_l << std::endl;
    std::cerr << "server.fullstate_r: " <<_model.server.fullstate_r << std::endl;
    std::cerr << "server.game_log_compression: " <<_model.server.game_log_compression
              << std::endl;
    std::cerr << "server.game_log_dated: " <<_model.server.game_log_dated << std::endl;
    std::cerr << "server.game_log_dir: " <<_model.server.game_log_dir << std::endl;
    std::cerr << "server.game_log_fixed: " <<_model.server.game_log_fixed << std::endl;
    std::cerr << "server.game_log_fixed_name: " <<_model.server.game_log_fixed_name << std::endl;
    std::cerr << "server.game_log_version: " <<_model.server.game_log_version << std::endl;
    std::cerr << "server.game_logging: " <<_model.server.game_logging << std::endl;
    std::cerr << "server.game_over_wait: " <<_model.server.game_over_wait << std::endl;
    std::cerr << "server.goal_width: " <<_model.server.goal_width << std::endl;
    std::cerr << "server.goalie_max_moves: " <<_model.server.goalie_max_moves << std::endl;
    std::cerr << "server.golden_goal: " <<_model.server.golden_goal << std::endl;
    std::cerr << "server.half_time: " <<_model.server.half_time << std::endl;
    std::cerr << "server.hear_decay: " <<_model.server.hear_decay << std::endl;
    std::cerr << "server.hear_inc: " <<_model.server.hear_inc << std::endl;
    std::cerr << "server.hear_max: " <<_model.server.hear_max << std::endl;
    std::cerr << "server.inertia_moment: " <<_model.server.inertia_moment << std::endl;
    std::cerr << "server.keepaway: " <<_model.server.keepaway << std::endl;
    std::cerr << "server.keepaway_length: " <<_model.server.keepaway_length << std::endl;
    std::cerr << "server.keepaway_log_dated: " <<_model.server.keepaway_log_dated << std::endl;
    std::cerr << "server.keepaway_log_dir: " <<_model.server.keepaway_log_dir << std::endl;
    std::cerr << "server.keepaway_log_fixed: " <<_model.server.keepaway_log_fixed << std::endl;
    std::cerr << "server.keepaway_log_fixed_name: " <<_model.server.keepaway_log_fixed_name
              << std::endl;
    std::cerr << "server.keepaway_logging: " <<_model.server.keepaway_logging << std::endl;
    std::cerr << "server.keepaway_start: " <<_model.server.keepaway_start << std::endl;
    std::cerr << "server.keepaway_width: " <<_model.server.keepaway_width << std::endl;
    std::cerr << "server.kick_off_wait: " <<_model.server.kick_off_wait << std::endl;
    std::cerr << "server.kick_power_rate: " <<_model.server.kick_power_rate << std::endl;
    std::cerr << "server.kick_rand: " <<_model.server.kick_rand << std::endl;
    std::cerr << "server.kick_rand_factor_l: " <<_model.server.kick_rand_factor_l << std::endl;
    std::cerr << "server.kick_rand_factor_r: " <<_model.server.kick_rand_factor_r << std::endl;
    std::cerr << "server.kickable_margin: " <<_model.server.kickable_margin << std::endl;
    std::cerr << "server.landmark_file: " <<_model.server.landmark_file << std::endl;
    std::cerr << "server.log_date_format: " <<_model.server.log_date_format << std::endl;
    std::cerr << "server.log_times: " <<_model.server.log_times << std::endl;
    std::cerr << "server.max_back_tackle_power: " <<_model.server.max_back_tackle_power
              << std::endl;
    std::cerr << "server.max_dash_angle: " <<_model.server.max_dash_angle << std::endl;
    std::cerr << "server.max_dash_power: " <<_model.server.max_dash_power << std::endl;
    std::cerr << "server.max_goal_kicks: " <<_model.server.max_goal_kicks << std::endl;
    std::cerr << "server.max_tackle_power: " <<_model.server.max_tackle_power << std::endl;
    std::cerr << "server.maxmoment: " <<_model.server.maxmoment << std::endl;
    std::cerr << "server.maxneckang: " <<_model.server.maxneckang << std::endl;
    std::cerr << "server.maxneckmoment: " <<_model.server.maxneckmoment << std::endl;
    std::cerr << "server.maxpower: " <<_model.server.maxpower << std::endl;
    std::cerr << "server.min_dash_angle: " <<_model.server.min_dash_angle << std::endl;
    std::cerr << "server.min_dash_power: " <<_model.server.min_dash_power << std::endl;
    std::cerr << "server.minmoment: " <<_model.server.minmoment << std::endl;
    std::cerr << "server.minneckang: " <<_model.server.minneckang << std::endl;
    std::cerr << "server.minneckmoment: " <<_model.server.minneckmoment << std::endl;
    std::cerr << "server.minpower: " <<_model.server.minpower << std::endl;
    std::cerr << "server.nr_extra_halfs: " <<_model.server.nr_extra_halfs << std::endl;
    std::cerr << "server.nr_normal_halfs: " <<_model.server.nr_normal_halfs << std::endl;
    std::cerr << "server.offside_active_area_size "
              <<_model.server.offside_active_area_size << std::endl;
    std::cerr << "server.offside_kick_margin: " <<_model.server.offside_kick_margin << std::endl;
    std::cerr << "server.olcoach_port: " <<_model.server.olcoach_port << std::endl;
    std::cerr << "server.old_coach_hear: " <<_model.server.old_coach_hear << std::endl;
    std::cerr << "server.pen_allow_mult_kicks: " <<_model.server.pen_allow_mult_kicks
              << std::endl;
    std::cerr << "server.pen_before_setup_wait: " <<_model.server.pen_before_setup_wait
              << std::endl;
    std::cerr << "server.pen_coach_moves_players: " <<_model.server.pen_coach_moves_players
              << std::endl;
    std::cerr << "server.pen_dist_x: " <<_model.server.pen_dist_x << std::endl;
    std::cerr << "server.pen_max_extra_kicks: " <<_model.server.pen_max_extra_kicks << std::endl;
    std::cerr << "server.pen_max_goalie_dist_x: " <<_model.server.pen_max_goalie_dist_x
              << std::endl;
    std::cerr << "server.pen_nr_kicks: " <<_model.server.pen_nr_kicks << std::endl;
    std::cerr << "server.pen_random_winner: " <<_model.server.pen_random_winner << std::endl;
    std::cerr << "server.pen_ready_wait: " <<_model.server.pen_ready_wait << std::endl;
    std::cerr << "server.pen_setup_wait: " <<_model.server.pen_setup_wait << std::endl;
    std::cerr << "server.pen_taken_wait: " <<_model.server.pen_taken_wait << std::endl;
    std::cerr << "server.penalty_shoot_outs: " <<_model.server.penalty_shoot_outs << std::endl;
    std::cerr << "server.player_accel_max: " <<_model.server.player_accel_max << std::endl;
    std::cerr << "server.player_decay: " <<_model.server.player_decay << std::endl;
    std::cerr << "server.player_rand: " <<_model.server.player_rand << std::endl;
    std::cerr << "server.player_size: " <<_model.server.player_size << std::endl;
    std::cerr << "server.player_speed_max: " <<_model.server.player_speed_max << std::endl;
    std::cerr << "server.player_speed_max_min: " <<_model.server.player_speed_max_min
              << std::endl;
    std::cerr << "server.player_weight: " <<_model.server.player_weight << std::endl;
    std::cerr << "server.point_to_ban: " <<_model.server.point_to_ban << std::endl;
    std::cerr << "server.point_to_duration: " <<_model.server.point_to_duration << std::endl;
    std::cerr << "server.port: " <<_model.server.port << std::endl;
    std::cerr << "server.prand_factor_l: " <<_model.server.prand_factor_l << std::endl;
    std::cerr << "server.prand_factor_r: " <<_model.server.prand_factor_r << std::endl;
    std::cerr << "server.profile: " <<_model.server.profile << std::endl;
    std::cerr << "server.proper_goal_kicks: " <<_model.server.proper_goal_kicks << std::endl;
    std::cerr << "server.quantize_step: " <<_model.server.quantize_step << std::endl;
    std::cerr << "server.quantize_step_l: " <<_model.server.quantize_step_l << std::endl;
    std::cerr << "server.record_messages: " <<_model.server.record_messages << std::endl;
    std::cerr << "server.recover_dec: " <<_model.server.recover_dec << std::endl;
    std::cerr << "server.recover_dec_thr: " <<_model.server.recover_dec_thr << std::endl;
    std::cerr << "server.recover_init: " <<_model.server.recover_init << std::endl;
    std::cerr << "server.recover_min: " <<_model.server.recover_min << std::endl;
    std::cerr << "server.recv_step: " <<_model.server.recv_step << std::endl;
    std::cerr << "server.red_card_probability: " <<_model.server.red_card_probability
              << std::endl;
    std::cerr << "server.say_coach_cnt_max: " <<_model.server.say_coach_cnt_max << std::endl;
    std::cerr << "server.say_coach_msg_size: " <<_model.server.say_coach_msg_size << std::endl;
    std::cerr << "server.say_msg_size: " <<_model.server.say_msg_size << std::endl;
    std::cerr << "server.send_comms: " <<_model.server.send_comms << std::endl;
    std::cerr << "server.send_step: " <<_model.server.send_step << std::endl;
    std::cerr << "server.send_vi_step: " <<_model.server.send_vi_step << std::endl;
    std::cerr << "server.sense_body_step: " <<_model.server.sense_body_step << std::endl;
    std::cerr << "server.side_dash_rate: " <<_model.server.side_dash_rate << std::endl;
    std::cerr << "server.simulator_step: " <<_model.server.simulator_step << std::endl;
    std::cerr << "server.slow_down_factor: " <<_model.server.slow_down_factor << std::endl;
    std::cerr << "server.slowness_on_top_for_left_team "
              <<_model.server.slowness_on_top_for_left_team << std::endl;
    std::cerr << "server.slowness_on_top_for_right_team "
              <<_model.server.slowness_on_top_for_right_team << std::endl;
    std::cerr << "server.stamina_capacity: " <<_model.server.stamina_capacity << std::endl;
    std::cerr << "server.stamina_inc_max: " <<_model.server.stamina_inc_max << std::endl;
    std::cerr << "server.stamina_max: " <<_model.server.stamina_max << std::endl;
    std::cerr << "server.start_goal_l: " <<_model.server.start_goal_l << std::endl;
    std::cerr << "server.start_goal_r: " <<_model.server.start_goal_r << std::endl;
    std::cerr << "server.stopped_ball_vel: " <<_model.server.stopped_ball_vel << std::endl;
    std::cerr << "server.synch_micro_sleep: " <<_model.server.synch_micro_sleep << std::endl;
    std::cerr << "server.synch_mode: " <<_model.server.synch_mode << std::endl;
    std::cerr << "server.synch_offset: " <<_model.server.synch_offset << std::endl;
    std::cerr << "server.synch_see_offset: " <<_model.server.synch_see_offset << std::endl;
    std::cerr << "server.tackle_back_dist: " <<_model.server.tackle_back_dist << std::endl;
    std::cerr << "server.tackle_cycles: " <<_model.server.tackle_cycles << std::endl;
    std::cerr << "server.tackle_dist: " <<_model.server.tackle_dist << std::endl;
    std::cerr << "server.tackle_exponent: " <<_model.server.tackle_exponent << std::endl;
    std::cerr << "server.tackle_power_rate: " <<_model.server.tackle_power_rate << std::endl;
    std::cerr << "server.tackle_rand_factor: " <<_model.server.tackle_rand_factor << std::endl;
    std::cerr << "server.tackle_width: " <<_model.server.tackle_width << std::endl;
    std::cerr << "server.team_actuator_noise: " <<_model.server.team_actuator_noise << std::endl;
    std::cerr << "server.team_l_start: " <<_model.server.team_l_start << std::endl;
    std::cerr << "server.team_r_start: " <<_model.server.team_r_start << std::endl;
    std::cerr << "server.text_log_compression: " <<_model.server.text_log_compression
              << std::endl;
    std::cerr << "server.text_log_dated: " <<_model.server.text_log_dated << std::endl;
    std::cerr << "server.text_log_dir: " <<_model.server.text_log_dir << std::endl;
    std::cerr << "server.text_log_fixed: " <<_model.server.text_log_fixed << std::endl;
    std::cerr << "server.text_log_fixed_name: " <<_model.server.text_log_fixed_name << std::endl;
    std::cerr << "server.text_logging: " <<_model.server.text_logging << std::endl;
    std::cerr << "server.use_offside: " <<_model.server.use_offside << std::endl;
    std::cerr << "server.verbose: " <<_model.server.verbose << std::endl;
    std::cerr << "server.visible_angle: " <<_model.server.visible_angle << std::endl;
    std::cerr << "server.visible_distance: " <<_model.server.visible_distance << std::endl;
    std::cerr << "server.wind_ang: " <<_model.server.wind_ang << std::endl;
    std::cerr << "server.wind_dir: " <<_model.server.wind_dir << std::endl;
    std::cerr << "server.wind_force: " <<_model.server.wind_force << std::endl;
    std::cerr << "server.wind_none: " <<_model.server.wind_none << std::endl;
    std::cerr << "server.wind_rand: " <<_model.server.wind_rand << std::endl;
    std::cerr << "server.wind_random: " <<_model.server.wind_random << std::endl;
}

void u2d::agent::print_player_param() {
    std::cerr << "player.allow_mult_default_type: " << _model.player.allow_mult_default_type<< std::endl;
    std::cerr << "player.catchable_area_l_stretch_max: " << _model.player.catchable_area_l_stretch_max<< std::endl;
    std::cerr << "player.catchable_area_l_stretch_min: " << _model.player.catchable_area_l_stretch_min<< std::endl;
    std::cerr << "player.dash_power_rate_delta_max: " << _model.player.dash_power_rate_delta_max<< std::endl;
    std::cerr << "player.dash_power_rate_delta_min: " << _model.player.dash_power_rate_delta_min<< std::endl;
    std::cerr << "player.effort_max_delta_factor: " << _model.player.effort_max_delta_factor<< std::endl;
    std::cerr << "player.effort_min_delta_factor: " << _model.player.effort_min_delta_factor<< std::endl;
    std::cerr << "player.extra_stamina_delta_max: " << _model.player.extra_stamina_delta_max<< std::endl;
    std::cerr << "player.extra_stamina_delta_min: " << _model.player.extra_stamina_delta_min<< std::endl;
    std::cerr << "player.foul_detect_probability_delta_factor: " << _model.player.foul_detect_probability_delta_factor<< std::endl;
    std::cerr << "player.inertia_moment_delta_factor: " << _model.player.inertia_moment_delta_factor<< std::endl;
    std::cerr << "player.kick_power_rate_delta_max: " << _model.player.kick_power_rate_delta_max<< std::endl;
    std::cerr << "player.kick_power_rate_delta_min: " << _model.player.kick_power_rate_delta_min<< std::endl;
    std::cerr << "player.kick_rand_delta_factor: " << _model.player.kick_rand_delta_factor<< std::endl;
    std::cerr << "player.kickable_margin_delta_max: " << _model.player.kickable_margin_delta_max<< std::endl;
    std::cerr << "player.kickable_margin_delta_min: " << _model.player.kickable_margin_delta_min<< std::endl;
    std::cerr << "player.new_dash_power_rate_delta_max: " << _model.player.new_dash_power_rate_delta_max<< std::endl;
    std::cerr << "player.new_dash_power_rate_delta_min: " << _model.player.new_dash_power_rate_delta_min<< std::endl;
    std::cerr << "player.new_stamina_inc_max_delta_factor: " << _model.player.new_stamina_inc_max_delta_factor<< std::endl;
    std::cerr << "player.player_decay_delta_max: " << _model.player.player_decay_delta_max<< std::endl;
    std::cerr << "player.player_decay_delta_min: " << _model.player.player_decay_delta_min<< std::endl;
    std::cerr << "player.player_size_delta_factor: " << _model.player.player_size_delta_factor<< std::endl;
    std::cerr << "player.player_speed_max_delta_max: " << _model.player.player_speed_max_delta_max<< std::endl;
    std::cerr << "player.player_speed_max_delta_min: " << _model.player.player_speed_max_delta_min<< std::endl;
    std::cerr << "player.player_types: " << static_cast<int>(_model.player.player_types) << std::endl;
    std::cerr << "player.pt_max: " << static_cast<int>(_model.player.pt_max) << std::endl;
    std::cerr << "player.random_seed: " << _model.player.random_seed << std::endl;
    std::cerr << "player.stamina_inc_max_delta_factor: " << _model.player.stamina_inc_max_delta_factor<< std::endl;
    std::cerr << "player.subs_max: " << static_cast<int>(_model.player.subs_max)<< std::endl;
}

