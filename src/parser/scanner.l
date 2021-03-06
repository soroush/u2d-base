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

 %%
"("                                 return Parser::LP;
")"                                 return Parser::RP;
"server_param"                      return Parser::SERVER;
"arm"                               return Parser::ARM;
"audio_cut_dist"                    return Parser::ACD;
"auto_mode"                         return Parser::AM;
"back_dash_rate"                    return Parser::BDR;
"back_passes"                       return Parser::BP;
"ball_accel_max"                    return Parser::BAM;
"ball_decay"                        return Parser::BD;
"ball_rand"                         return Parser::BR;
"ball_size"                         return Parser::BS;
"ball_speed_max"                    return Parser::BSM;
"ball_stuck_area"                   return Parser::BSA;
"ball_weight"                       return Parser::BW;
"ball"                              return Parser::BALL;
"b"                                 return Parser::_B;
"B"                                 return Parser::_BB;
"before_kick_off"                   return Parser::PM_BKO;
"card"                              return Parser::CARD;
"catch_ban_cycle"                   return Parser::CBC;
"catch_probability"                 return Parser::CP;
"catchable_area_l_stretch_max"      return Parser::CALSMAX;
"catchable_area_l_stretch_min"      return Parser::CALSMIN;
"catchable_area_l"                  return Parser::CAL;
"catchable_area_w"                  return Parser::CAW;
"catchable_area_l_stretch"          return Parser::CALS;
"catch"                             return Parser::CATCH;
"change_view"                       return Parser::CHVIEW;
"charged"                           return Parser::CHARGED;
"ckick_margin"                      return Parser::CM;
"clang_advice_win"                  return Parser::CADW;
"clang_define_win"                  return Parser::CDEFW;
"clang_del_win"                     return Parser::CDELW;
"clang_info_win"                    return Parser::CIW;
"clang_mess_delay"                  return Parser::CMD;
"clang_mess_per_cycle"              return Parser::CMPC;
"coach"                             return Parser::CO;
"coach_port"                        return Parser::COP;
"coach_w_referee"                   return Parser::CWR;
"collision"                         return Parser::COLL;
"corner_kick_l"                     return Parser::PM_CKL;
"corner_kick_r"                     return Parser::PM_CKR;
"clang_meta_win"                    return Parser::CMW;
"clang_rule_win"                    return Parser::CRW;
"clang_win_size"                    return Parser::CWS;
"connect_wait"                      return Parser::CW;
"control_radius"                    return Parser::CR;
"count"                             return Parser::COUNT;
"c"                                 return Parser::_C;
"dash_angle_step"                   return Parser::DAS;
"dash_power_rate"                   return Parser::DPR;
"new_dash_power_rate_delta_max"     return Parser::NDPRDMAX;
"new_dash_power_rate_delta_min"     return Parser::NDPRDMIN;
"dash_power_rate_delta_max"         return Parser::DPRDMAX;
"dash_power_rate_delta_min"         return Parser::DPRDMIN;
"dash"                              return Parser::DASH;
"drop_ball"                         return Parser::PM_DB;
"drop_ball_time"                    return Parser::DBT;
"effort_max_delta_factor"           return Parser::EMAXDF;
"effort_min_delta_factor"           return Parser::EMINDF;
"effort_dec"                        return Parser::ED;
"effort_dec_thr"                    return Parser::EDT;
"effort_inc"                        return Parser::EIN;
"effort_inc_thr"                    return Parser::EIT;
"effort_init"                       return Parser::EI;
"effort_min"                        return Parser::EM;
"effort_max"                        return Parser::EMAX;
"expires"                           return Parser::EXP;
"extra_stamina_delta_max"           return Parser::ESDMAX;
"extra_stamina_delta_min"           return Parser::ESDMIN;
"extra_half_time"                   return Parser::EHT;
"extra_stamina"                     return Parser::ES;
"focus"                             return Parser::FOCUS;
"forbid_kick_off_offside"           return Parser::FKO;
"foul_cycles"                       return Parser::FC;
"foul_detect_probability_delta_factor"  return Parser::FDPDF;
"foul_detect_probability"           return Parser::FDP;
"foul_exponent"                     return Parser::FE;
"foul"                              return Parser::FOUL;
"free_kick_l"                       return Parser::PM_FKL;
"free_kick_r"                       return Parser::PM_FKR;
"free_kick_faults"                  return Parser::FKF;
"freeform_send_period"              return Parser::FSP;
"freeform_wait_period"              return Parser::FWP;
"fullstate_l"                       return Parser::FL;
"fullstate_r"                       return Parser::FR;
"f"                                 return Parser::_F;
"F"                                 return Parser::_FF;
"game_log_compression"              return Parser::GLC;
"game_log_dated"                    return Parser::GLD;
"game_log_dir"                      return Parser::GLDIR;
"game_log_fixed"                    return Parser::GLF;
"game_log_fixed_name"               return Parser::GLFN;
"game_log_version"                  return Parser::GLV;
"game_logging"                      return Parser::GL;
"game_over_wait"                    return Parser::GOW;
"goal_l"                            return Parser::PM_GOALL;
"goal_r"                            return Parser::PM_GOALR;
"goal_kick_l"                       return Parser::PM_GKL;
"goal_kick_r"                       return Parser::PM_GKR;
"goal_width"                        return Parser::GW;
"goalie_max_moves"                  return Parser::GMM;
"goalie"                            return Parser::GOALIE;
"golden_goal"                       return Parser::GG;
"g"                                 return Parser::_G;
"G"                                 return Parser::_GG;
"half_time"                         return Parser::HT;
"head_angle"                        return Parser::HA;
"hear_decay"                        return Parser::HD;
"hear_inc"                          return Parser::HI;
"hear_max"                          return Parser::HM;
"inertia_moment_delta_factor"       return Parser::IMDF;
"inertia_moment"                    return Parser::IM;
"id"                                return Parser::ID;
"keepaway"                          return Parser::K;
"keepaway_length"                   return Parser::KL;
"keepaway_log_dated"                return Parser::KLD;
"keepaway_log_dir"                  return Parser::KLDIR;
"keepaway_log_fixed"                return Parser::LKF;
"keepaway_log_fixed_name"           return Parser::KLFN;
"keepaway_logging"                  return Parser::KLG;
"keepaway_start"                    return Parser::KS;
"keepaway_width"                    return Parser::KW;
"kick_off_l"                        return Parser::PM_KOL;
"kick_off_r"                        return Parser::PM_KOR;
"kick_in_l"                         return Parser::PM_KIL;
"kick_in_r"                         return Parser::PM_KIR;
"kick_off_wait"                     return Parser::KOW;
"kick_power_rate_delta_max"         return Parser::KPRDMAX;
"kick_power_rate_delta_min"         return Parser::KPRDMIN;
"kick_power_rate"                   return Parser::KPR;
"kick_rand_delta_factor"            return Parser::KPRDF; // should be KRDF in fact!
"kick_rand_factor_l"                return Parser::KRFL;
"kick_rand_factor_r"                return Parser::KRFR;
"kick_rand"                         return Parser::KR;
"kickable_margin"                   return Parser::KM;
"kickable_margin_delta_max"         return Parser::KMDMAX;
"kickable_margin_delta_min"         return Parser::KMDMIN;
"kick"                              return Parser::KICK;
"landmark_file"                     return Parser::LF;
"log_date_format"                   return Parser::LDF;
"log_times"                         return Parser::LT;
"l"                                 return Parser::_L;
"max_back_tackle_power"             return Parser::MBTP;
"max_dash_angle"                    return Parser::MAXDA;
"max_dash_power"                    return Parser::MDP;
"max_goal_kicks"                    return Parser::MGK;
"max_tackle_power"                  return Parser::MTP;
"maxmoment"                         return Parser::MAXM;
"maxneckang"                        return Parser::MAXNA;
"maxneckmoment"                     return Parser::MAXNM;
"maxpower"                          return Parser::MAXP;
"min_dash_angle"                    return Parser::MINDA;
"min_dash_power"                    return Parser::MINDP;
"minmoment"                         return Parser::MINM;
"minneckang"                        return Parser::MINNA;
"minneckmoment"                     return Parser::MINNM;
"minpower"                          return Parser::MINP;
"movable"                           return Parser::MOVABLE;
"move"                              return Parser::MOVE;
"nr_extra_halfs"                    return Parser::NEH;
"nr_normal_halfs"                   return Parser::NNH;
"offside_l"                         return Parser::PM_OL;
"offside_r"                         return Parser::PM_OR;
"offside_active_area_size"          return Parser::OAAS;
"offside_kick_margin"               return Parser::OKM;
"olcoach_port"                      return Parser::OP;
"old_coach_hear"                    return Parser::OCH;
"pen_allow_mult_kicks"              return Parser::PAMK;
"pen_before_setup_wait"             return Parser::PBSW;
"pen_coach_moves_players"           return Parser::PCMP;
"pen_dist_x"                        return Parser::PDX;
"pen_max_extra_kicks"               return Parser::PMET;
"pen_max_goalie_dist_x"             return Parser::PMGDX;
"pen_nr_kicks"                      return Parser::PNK;
"pen_random_winner"                 return Parser::PRW;
"pen_ready_wait"                    return Parser::PRWA;
"pen_setup_wait"                    return Parser::PSW;
"pen_taken_wait"                    return Parser::PTW;
"penalty_shoot_outs"                return Parser::PSO;
"player_accel_max"                  return Parser::PAM;
"player_decay"                      return Parser::PD;
"player_decay_delta_max"            return Parser::PDDMAX;
"player_decay_delta_min"            return Parser::PDDMIN;
"play_on"                           return Parser::PM_PO;
"player_rand"                       return Parser::PR;
"player_size"                       return Parser::PS;
"player_size_delta_factor"          return Parser::PSDF;
"player_speed_max"                  return Parser::PSM;
"player_speed_max_min"              return Parser::PSMM;
"player_speed_max_delta_max"        return Parser::PSMAXDMAX;
"player_speed_max_delta_min"        return Parser::PSMAXDMIN;
"player_types"                      return Parser::PT;
"player_type"                       return Parser::PTY;
"pt_max"                            return Parser::PTM;
"player_weight"                     return Parser::PW;
"player"                            return Parser::PLAYER;
"point_to_ban"                      return Parser::PTB;
"point_to_duration"                 return Parser::PTD;
"port"                              return Parser::P;
"post"                              return Parser::POST;
"prand_factor_l"                    return Parser::PFL;
"prand_factor_r"                    return Parser::PFR;
"profile"                           return Parser::PROF;
"p"                                 return Parser::_P;
"P"                                 return Parser::_PP;
"proper_goal_kicks"                 return Parser::PGK;
"quantize_step"                     return Parser::QS;
"quantize_step_l"                   return Parser::QSL;
"random_seed"                       return Parser::RANS;
"record_messages"                   return Parser::RM;
"recover_dec"                       return Parser::RD;
"recover_dec_thr"                   return Parser::RDT;
"recover_init"                      return Parser::RI;
"recover_min"                       return Parser::RMIN;
"recv_step"                         return Parser::RS;
"red_card_probability"              return Parser::RCP;
"r"                                 return Parser::_R;
"say_coach_cnt_max"                 return Parser::SCCM;
"say_coach_msg_size"                return Parser::SCMS;
"say_msg_size"                      return Parser::SMS;
"say"                               return Parser::SAY;
"see"                               return Parser::SEE; // Should be SC in fact!
"send_comms"                        return Parser::SM; // Should be SC in fact!
"send_step"                         return Parser::SS;
"send_vi_step"                      return Parser::SVS;
"sense_body_step"                   return Parser::SBS;
"sense_body"                        return Parser::SEN;
"side_dash_rate"                    return Parser::SDR;
"simulator_step"                    return Parser::SIMS;
"slow_down_factor"                  return Parser::SDF;
"slowness_on_top_for_left_team"     return Parser::SOTFLT;
"slowness_on_top_for_right_team"    return Parser::SOTFRT;
"speed"                             return Parser::SP;
"stamina_capacity"                  return Parser::SC;
"stamina_inc_max"                   return Parser::SIM;
"new_stamina_inc_max_delta_factor"  return Parser::NSIMAXDF;
"stamina_inc_max_delta_factor"      return Parser::SIMAXDF;
"stamina_max"                       return Parser::SMAX;
"stamina"                           return Parser::ST;
"start_goal_l"                      return Parser::SGL;
"start_goal_r"                      return Parser::SGR;
"stopped_ball_vel"                  return Parser::SBV;
"subs_max"                          return Parser::SUBMAX;
"synch_micro_sleep"                 return Parser::SMICS;
"synch_mode"                        return Parser::SMOD;
"synch_offset"                      return Parser::SO;
"synch_see_offset"                  return Parser::SSO;
"tackle_back_dist"                  return Parser::TBD;
"tackle_cycles"                     return Parser::TC;
"tackle_dist"                       return Parser::TD;
"tackle_exponent"                   return Parser::TE;
"tackle_power_rate"                 return Parser::TPR;
"tackle_rand_factor"                return Parser::TRF;
"tackle_width"                      return Parser::TW;
"tackle"                            return Parser::TACKLE;
"target"                            return Parser::TAR;
"team_actuator_noise"               return Parser::TAN;
"team_l_start"                      return Parser::TLS;
"team_r_start"                      return Parser::TRS;
"text_log_compression"              return Parser::TLC;
"text_log_dated"                    return Parser::TLD;
"text_log_dir"                      return Parser::TLDIR;
"text_log_fixed"                    return Parser::TLF;
"text_log_fixed_name"               return Parser::TLFN;
"text_logging"                      return Parser::TL;
"time_over"                         return Parser::PM_TO;
"turn_neck"                         return Parser::TNECK;
"turn"                              return Parser::TURN;
"t"                                 return Parser::_T;
"use_offside"                       return Parser::UO;
"verbose"                           return Parser::V;
"visible_angle"                     return Parser::VA;
"visible_distance"                  return Parser::VD;
"view_mode"                         return Parser::VM;
"high"                              return Parser::VQ_H;
"low"                               return Parser::VQ_L;
"narrow"                            return Parser::VW_NA;
"normal"                            return Parser::VW_NO;
"none"                              return Parser::NONE;
"yellow"                            return Parser::YELLOW;
"wide"                              return Parser::VW_WI;
"wind_ang"                          return Parser::WA;
"wind_dir"                          return Parser::WD;
"wind_force"                        return Parser::WF;
"wind_none"                         return Parser::WN;
"wind_rand"                         return Parser::WR;
"wind_random"                       return Parser::WRA;
"init"                              return Parser::INIT;
"player_param"                      return Parser::PP;
"allow_mult_default_type"           return Parser::AMDT;
"hear"                              return Parser::HEAR;
"online_coach_left"                 return Parser::OCL;
"online_coach_right"                return Parser::OCR;
"referee"                           return Parser::REFEREE;
"self"                              return Parser::SELF;
"0"                                 return Parser::_0;
"1"                                 return Parser::_1;
"10"                                return Parser::_10;
"20"                                return Parser::_20;
"30"                                return Parser::_30;
"40"                                return Parser::_40;
"50"                                return Parser::_50;
"-"?[[:digit:]]+                    return Parser::INTEGER;
"-"?[[:digit:]]+("."[[:digit:]]+)?  return Parser::DOUBLE;
"\""[^\"]*"\""                      return Parser::STRING;
[ \t\n]+                            ;
