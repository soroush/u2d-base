/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2016-2022 Soroush Rabiei <soroush.rabiei@gmail.com>

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

%namespace                 u2d
%baseclass-header          "scanner-base.hpp"
%class-header              "scanner.hpp"
%implementation-header     "scanner-impl.hpp"
%lex-source                "scanner.cpp"
%class-name                "scanner"

 %%
"("                                 return u2d::parser::LP;
")"                                 return u2d::parser::RP;
"server_param"                      return u2d::parser::SERVER;
"arm"                               return u2d::parser::ARM;
"audio_cut_dist"                    return u2d::parser::ACD;
"auto_mode"                         return u2d::parser::AM;
"back_dash_rate"                    return u2d::parser::BDR;
"back_passes"                       return u2d::parser::BP;
"ball_accel_max"                    return u2d::parser::BAM;
"ball_decay"                        return u2d::parser::BD;
"ball_rand"                         return u2d::parser::BR;
"ball_size"                         return u2d::parser::BS;
"ball_speed_max"                    return u2d::parser::BSM;
"ball_stuck_area"                   return u2d::parser::BSA;
"ball_weight"                       return u2d::parser::BW;
"ball"                              return u2d::parser::BALL;
"b"                                 return u2d::parser::_B;
"B"                                 return u2d::parser::_BB;
"before_kick_off"                   return u2d::parser::PM_BKO;
"card"                              return u2d::parser::CARD;
"catch_ban_cycle"                   return u2d::parser::CBC;
"catch_probability"                 return u2d::parser::CP;
"catchable_area_l_stretch_max"      return u2d::parser::CALSMAX;
"catchable_area_l_stretch_min"      return u2d::parser::CALSMIN;
"catchable_area_l"                  return u2d::parser::CAL;
"catchable_area_w"                  return u2d::parser::CAW;
"catchable_area_l_stretch"          return u2d::parser::CALS;
"catch"                             return u2d::parser::CATCH;
"change_view"                       return u2d::parser::CHVIEW;
"charged"                           return u2d::parser::CHARGED;
"ckick_margin"                      return u2d::parser::CM;
"clang_advice_win"                  return u2d::parser::CADW;
"clang_define_win"                  return u2d::parser::CDEFW;
"clang_del_win"                     return u2d::parser::CDELW;
"clang_info_win"                    return u2d::parser::CIW;
"clang_mess_delay"                  return u2d::parser::CMD;
"clang_mess_per_cycle"              return u2d::parser::CMPC;
"coach"                             return u2d::parser::CO;
"coach_port"                        return u2d::parser::COP;
"coach_w_referee"                   return u2d::parser::CWR;
"collision"                         return u2d::parser::COLL;
"corner_kick_l"                     return u2d::parser::PM_CKL;
"corner_kick_r"                     return u2d::parser::PM_CKR;
"clang_meta_win"                    return u2d::parser::CMW;
"clang_rule_win"                    return u2d::parser::CRW;
"clang_win_size"                    return u2d::parser::CWS;
"connect_wait"                      return u2d::parser::CW;
"control_radius"                    return u2d::parser::CR;
"count"                             return u2d::parser::COUNT;
"c"                                 return u2d::parser::_C;
"dash_angle_step"                   return u2d::parser::DAS;
"dash_power_rate"                   return u2d::parser::DPR;
"new_dash_power_rate_delta_max"     return u2d::parser::NDPRDMAX;
"new_dash_power_rate_delta_min"     return u2d::parser::NDPRDMIN;
"dash_power_rate_delta_max"         return u2d::parser::DPRDMAX;
"dash_power_rate_delta_min"         return u2d::parser::DPRDMIN;
"dash"                              return u2d::parser::DASH;
"drop_ball"                         return u2d::parser::PM_DB;
"drop_ball_time"                    return u2d::parser::DBT;
"effort_max_delta_factor"           return u2d::parser::EMAXDF;
"effort_min_delta_factor"           return u2d::parser::EMINDF;
"effort_dec"                        return u2d::parser::ED;
"effort_dec_thr"                    return u2d::parser::EDT;
"effort_inc"                        return u2d::parser::EIN;
"effort_inc_thr"                    return u2d::parser::EIT;
"effort_init"                       return u2d::parser::EI;
"effort_min"                        return u2d::parser::EM;
"effort_max"                        return u2d::parser::EMAX;
"expires"                           return u2d::parser::EXP;
"extra_stamina_delta_max"           return u2d::parser::ESDMAX;
"extra_stamina_delta_min"           return u2d::parser::ESDMIN;
"extra_half_time"                   return u2d::parser::EHT;
"extra_stamina"                     return u2d::parser::ES;
"focus"                             return u2d::parser::FOCUS;
"forbid_kick_off_offside"           return u2d::parser::FKO;
"foul_cycles"                       return u2d::parser::FC;
"foul_detect_probability_delta_factor"  return u2d::parser::FDPDF;
"foul_detect_probability"           return u2d::parser::FDP;
"foul_exponent"                     return u2d::parser::FE;
"foul"                              return u2d::parser::FOUL;
"free_kick_l"                       return u2d::parser::PM_FKL;
"free_kick_r"                       return u2d::parser::PM_FKR;
"free_kick_faults"                  return u2d::parser::FKF;
"freeform_send_period"              return u2d::parser::FSP;
"freeform_wait_period"              return u2d::parser::FWP;
"fullstate_l"                       return u2d::parser::FL;
"fullstate_r"                       return u2d::parser::FR;
"f"                                 return u2d::parser::_F;
"F"                                 return u2d::parser::_FF;
"game_log_compression"              return u2d::parser::GLC;
"game_log_dated"                    return u2d::parser::GLD;
"game_log_dir"                      return u2d::parser::GLDIR;
"game_log_fixed"                    return u2d::parser::GLF;
"game_log_fixed_name"               return u2d::parser::GLFN;
"game_log_version"                  return u2d::parser::GLV;
"game_logging"                      return u2d::parser::GL;
"game_over_wait"                    return u2d::parser::GOW;
"goal_l"                            return u2d::parser::PM_GOALL;
"goal_r"                            return u2d::parser::PM_GOALR;
"goal_kick_l"                       return u2d::parser::PM_GKL;
"goal_kick_r"                       return u2d::parser::PM_GKR;
"goal_width"                        return u2d::parser::GW;
"goalie_max_moves"                  return u2d::parser::GMM;
"goalie"                            return u2d::parser::GOALIE;
"golden_goal"                       return u2d::parser::GG;
"g"                                 return u2d::parser::_G;
"G"                                 return u2d::parser::_GG;
"half_time"                         return u2d::parser::HT;
"head_angle"                        return u2d::parser::HA;
"hear_decay"                        return u2d::parser::HD;
"hear_inc"                          return u2d::parser::HI;
"hear_max"                          return u2d::parser::HM;
"inertia_moment_delta_factor"       return u2d::parser::IMDF;
"inertia_moment"                    return u2d::parser::IM;
"id"                                return u2d::parser::ID;
"keepaway"                          return u2d::parser::K;
"keepaway_length"                   return u2d::parser::KL;
"keepaway_log_dated"                return u2d::parser::KLD;
"keepaway_log_dir"                  return u2d::parser::KLDIR;
"keepaway_log_fixed"                return u2d::parser::LKF;
"keepaway_log_fixed_name"           return u2d::parser::KLFN;
"keepaway_logging"                  return u2d::parser::KLG;
"keepaway_start"                    return u2d::parser::KS;
"keepaway_width"                    return u2d::parser::KW;
"kick_off_l"                        return u2d::parser::PM_KOL;
"kick_off_r"                        return u2d::parser::PM_KOR;
"kick_in_l"                         return u2d::parser::PM_KIL;
"kick_in_r"                         return u2d::parser::PM_KIR;
"kick_off_wait"                     return u2d::parser::KOW;
"kick_power_rate_delta_max"         return u2d::parser::KPRDMAX;
"kick_power_rate_delta_min"         return u2d::parser::KPRDMIN;
"kick_power_rate"                   return u2d::parser::KPR;
"kick_rand_delta_factor"            return u2d::parser::KPRDF; // should be KRDF in fact!
"kick_rand_factor_l"                return u2d::parser::KRFL;
"kick_rand_factor_r"                return u2d::parser::KRFR;
"kick_rand"                         return u2d::parser::KR;
"kickable_margin"                   return u2d::parser::KM;
"kickable_margin_delta_max"         return u2d::parser::KMDMAX;
"kickable_margin_delta_min"         return u2d::parser::KMDMIN;
"kick"                              return u2d::parser::KICK;
"landmark_file"                     return u2d::parser::LF;
"log_date_format"                   return u2d::parser::LDF;
"log_times"                         return u2d::parser::LT;
"l"                                 return u2d::parser::_L;
"max_back_tackle_power"             return u2d::parser::MBTP;
"max_dash_angle"                    return u2d::parser::MAXDA;
"max_dash_power"                    return u2d::parser::MDP;
"max_goal_kicks"                    return u2d::parser::MGK;
"max_tackle_power"                  return u2d::parser::MTP;
"maxmoment"                         return u2d::parser::MAXM;
"maxneckang"                        return u2d::parser::MAXNA;
"maxneckmoment"                     return u2d::parser::MAXNM;
"maxpower"                          return u2d::parser::MAXP;
"min_dash_angle"                    return u2d::parser::MINDA;
"min_dash_power"                    return u2d::parser::MINDP;
"minmoment"                         return u2d::parser::MINM;
"minneckang"                        return u2d::parser::MINNA;
"minneckmoment"                     return u2d::parser::MINNM;
"minpower"                          return u2d::parser::MINP;
"movable"                           return u2d::parser::MOVABLE;
"move"                              return u2d::parser::MOVE;
"nr_extra_halfs"                    return u2d::parser::NEH;
"nr_normal_halfs"                   return u2d::parser::NNH;
"offside_l"                         return u2d::parser::PM_OL;
"offside_r"                         return u2d::parser::PM_OR;
"offside_active_area_size"          return u2d::parser::OAAS;
"offside_kick_margin"               return u2d::parser::OKM;
"olcoach_port"                      return u2d::parser::OP;
"old_coach_hear"                    return u2d::parser::OCH;
"pen_allow_mult_kicks"              return u2d::parser::PAMK;
"pen_before_setup_wait"             return u2d::parser::PBSW;
"pen_coach_moves_players"           return u2d::parser::PCMP;
"pen_dist_x"                        return u2d::parser::PDX;
"pen_max_extra_kicks"               return u2d::parser::PMET;
"pen_max_goalie_dist_x"             return u2d::parser::PMGDX;
"pen_nr_kicks"                      return u2d::parser::PNK;
"pen_random_winner"                 return u2d::parser::PRW;
"pen_ready_wait"                    return u2d::parser::PRWA;
"pen_setup_wait"                    return u2d::parser::PSW;
"pen_taken_wait"                    return u2d::parser::PTW;
"penalty_shoot_outs"                return u2d::parser::PSO;
"player_accel_max"                  return u2d::parser::PAM;
"player_decay"                      return u2d::parser::PD;
"player_decay_delta_max"            return u2d::parser::PDDMAX;
"player_decay_delta_min"            return u2d::parser::PDDMIN;
"play_on"                           return u2d::parser::PM_PO;
"player_rand"                       return u2d::parser::PR;
"player_size"                       return u2d::parser::PS;
"player_size_delta_factor"          return u2d::parser::PSDF;
"player_speed_max"                  return u2d::parser::PSM;
"player_speed_max_min"              return u2d::parser::PSMM;
"player_speed_max_delta_max"        return u2d::parser::PSMAXDMAX;
"player_speed_max_delta_min"        return u2d::parser::PSMAXDMIN;
"player_types"                      return u2d::parser::PT;
"player_type"                       return u2d::parser::PTY;
"pt_max"                            return u2d::parser::PTM;
"player_weight"                     return u2d::parser::PW;
"player"                            return u2d::parser::PLAYER;
"point_to_ban"                      return u2d::parser::PTB;
"point_to_duration"                 return u2d::parser::PTD;
"port"                              return u2d::parser::P;
"post"                              return u2d::parser::POST;
"prand_factor_l"                    return u2d::parser::PFL;
"prand_factor_r"                    return u2d::parser::PFR;
"profile"                           return u2d::parser::PROF;
"p"                                 return u2d::parser::_P;
"P"                                 return u2d::parser::_PP;
"proper_goal_kicks"                 return u2d::parser::PGK;
"quantize_step"                     return u2d::parser::QS;
"quantize_step_l"                   return u2d::parser::QSL;
"random_seed"                       return u2d::parser::RANS;
"record_messages"                   return u2d::parser::RM;
"recover_dec"                       return u2d::parser::RD;
"recover_dec_thr"                   return u2d::parser::RDT;
"recover_init"                      return u2d::parser::RI;
"recover_min"                       return u2d::parser::RMIN;
"recv_step"                         return u2d::parser::RS;
"red_card_probability"              return u2d::parser::RCP;
"r"                                 return u2d::parser::_R;
"say_coach_cnt_max"                 return u2d::parser::SCCM;
"say_coach_msg_size"                return u2d::parser::SCMS;
"say_msg_size"                      return u2d::parser::SMS;
"say"                               return u2d::parser::SAY;
"see"                               return u2d::parser::SEE; // Should be SC in fact!
"send_comms"                        return u2d::parser::SM; // Should be SC in fact!
"send_step"                         return u2d::parser::SS;
"send_vi_step"                      return u2d::parser::SVS;
"sense_body_step"                   return u2d::parser::SBS;
"sense_body"                        return u2d::parser::SEN;
"side_dash_rate"                    return u2d::parser::SDR;
"simulator_step"                    return u2d::parser::SIMS;
"slow_down_factor"                  return u2d::parser::SDF;
"slowness_on_top_for_left_team"     return u2d::parser::SOTFLT;
"slowness_on_top_for_right_team"    return u2d::parser::SOTFRT;
"speed"                             return u2d::parser::SP;
"stamina_capacity"                  return u2d::parser::SC;
"stamina_inc_max"                   return u2d::parser::SIM;
"new_stamina_inc_max_delta_factor"  return u2d::parser::NSIMAXDF;
"stamina_inc_max_delta_factor"      return u2d::parser::SIMAXDF;
"stamina_max"                       return u2d::parser::SMAX;
"stamina"                           return u2d::parser::ST;
"start_goal_l"                      return u2d::parser::SGL;
"start_goal_r"                      return u2d::parser::SGR;
"stopped_ball_vel"                  return u2d::parser::SBV;
"subs_max"                          return u2d::parser::SUBMAX;
"synch_micro_sleep"                 return u2d::parser::SMICS;
"synch_mode"                        return u2d::parser::SMOD;
"synch_offset"                      return u2d::parser::SO;
"synch_see_offset"                  return u2d::parser::SSO;
"tackle_back_dist"                  return u2d::parser::TBD;
"tackle_cycles"                     return u2d::parser::TC;
"tackle_dist"                       return u2d::parser::TD;
"tackle_exponent"                   return u2d::parser::TE;
"tackle_power_rate"                 return u2d::parser::TPR;
"tackle_rand_factor"                return u2d::parser::TRF;
"tackle_width"                      return u2d::parser::TW;
"tackle"                            return u2d::parser::TACKLE;
"target"                            return u2d::parser::TAR;
"team_actuator_noise"               return u2d::parser::TAN;
"team_l_start"                      return u2d::parser::TLS;
"team_r_start"                      return u2d::parser::TRS;
"text_log_compression"              return u2d::parser::TLC;
"text_log_dated"                    return u2d::parser::TLD;
"text_log_dir"                      return u2d::parser::TLDIR;
"text_log_fixed"                    return u2d::parser::TLF;
"text_log_fixed_name"               return u2d::parser::TLFN;
"text_logging"                      return u2d::parser::TL;
"time_over"                         return u2d::parser::PM_TO;
"turn_neck"                         return u2d::parser::TNECK;
"turn"                              return u2d::parser::TURN;
"t"                                 return u2d::parser::_T;
"use_offside"                       return u2d::parser::UO;
"verbose"                           return u2d::parser::V;
"visible_angle"                     return u2d::parser::VA;
"visible_distance"                  return u2d::parser::VD;
"view_mode"                         return u2d::parser::VM;
"high"                              return u2d::parser::VQ_H;
"low"                               return u2d::parser::VQ_L;
"narrow"                            return u2d::parser::VW_NA;
"normal"                            return u2d::parser::VW_NO;
"none"                              return u2d::parser::NONE;
"yellow"                            return u2d::parser::YELLOW;
"wide"                              return u2d::parser::VW_WI;
"wind_ang"                          return u2d::parser::WA;
"wind_dir"                          return u2d::parser::WD;
"wind_force"                        return u2d::parser::WF;
"wind_none"                         return u2d::parser::WN;
"wind_rand"                         return u2d::parser::WR;
"wind_random"                       return u2d::parser::WRA;
"init"                              return u2d::parser::INIT;
"player_param"                      return u2d::parser::PP;
"allow_mult_default_type"           return u2d::parser::AMDT;
"hear"                              return u2d::parser::HEAR;
"online_coach_left"                 return u2d::parser::OCL;
"online_coach_right"                return u2d::parser::OCR;
"referee"                           return u2d::parser::REFEREE;
"self"                              return u2d::parser::SELF;
"0"                                 return u2d::parser::_0;
"1"                                 return u2d::parser::_1;
"10"                                return u2d::parser::_10;
"20"                                return u2d::parser::_20;
"30"                                return u2d::parser::_30;
"40"                                return u2d::parser::_40;
"50"                                return u2d::parser::_50;
"-"?[[:digit:]]+                    return u2d::parser::INTEGER;
"-"?[[:digit:]]+("."[[:digit:]]+)?  return u2d::parser::DOUBLE;
"\""[^\"]*"\""                      return u2d::parser::STRING;
[ \t\n]+                            ;
