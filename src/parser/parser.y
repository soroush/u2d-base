/*
 libU2D, Robocup 2D Soccer Server Simulation base of U2D Team.

 Copyright (c) 2011, 2012, 2013 Soroush Rabiei <soroush-r@users.sf.net>

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

%scanner                ./Scanner.h
%baseclass-preinclude   "./temporary_data.h"
%baseclass-preinclude   "../model/visual-objects/flag.h"
%baseclass-preinclude   "../model/visual-objects/line.h"
%scanner-token-function d_scanner.lex()

%union{
double		d;
int		i;
bool		b;
std::string*	s;
flag_data*	f;
line_data*	l;
}

%token <d> 	DOUBLE
%token <i> 	INTEGER
%token <s> 	STRING

%token INIT
%token SERVER
%token LP
%token RP

//global tokens:
_0 _1 _10 _20 _30 _40 _50

// server_param:
%token ACD AM BDR BP BAM BD BR BS BSM BSA BW CBC CP CAL CAW CM CADW CDEFW CDELW
CIW CMD CMPC CMW CRW CWS CO COP CWR CW CR DAS DPR DBT ED EDT EIN EIT EI EM EHT
ES FKO FC FDP FE FKF FSP FWP FL FR GLC GLD GLDIR GLF GLFN GLV GL GOW GW GMM GG
HT HD HI HM IM K KL KLD KLDIR LKF KLFN KLG KS KW KOW KPR KR KRFL KRFR KM LF LDF
LT MBTP MAXDA MDP MGK MTP MAXM MAXNA MAXNM MAXP MINDA MINDP MINM MINNA MINNM
MINP NEH NNH OAAS OKM OP OCH PAMK PBSW PCMP PDX PMET PMGDX PNK PRW PRWA PSW PTW
PSO PAM PD PR PS PSM PSMM PW PTB PTD P PFL PFR PROF PGK QS QSL RM RD RDT RI
RMIN RS RCP SCCM SCMS SMS SM SS SVS SBS SDR SIMS SDF SOTFLT SOTFRT SC SIM SMAX
SGL SGR SBV SMICS SMOD  SO SSO TBD TC TD TE TPR TRF TW TAN TLS TRS TLC TLD
TLDIR TLF TLFN TL UO V VA VD WA WD WF WN WR WRA

// player_param:
%token PP AMDT CALSMAX CALSMIN DPRDMAX DPRDMIN EMAXDF EMINDF ESDMAX ESDMIN FDPDF IMDF
KPRDMAX KPRDMIN KPRDF KMDMAX KMDMIN NDPRDMAX NDPRDMIN NSIMAXDF PDDMAX PDDMIN
PSDF PSMAXDMAX PSMAXDMIN PT PTM RANS SIMAXDF SUBMAX

// player_type:
%token PTY ID EMAX CALS

// play_mode:
%token PM_BKO PM_PO PM_TO PM_KOL PM_KOR PM_KIL PM_KIR PM_FKL PM_FKR
PM_CKL PM_CKR PM_GKL PM_GKR PM_GOALL PM_GOALR PM_DB PM_OL PM_OR

// sense_body:
%token SEN VM VQ_L VQ_H VW_NA VW_NO VW_WI ST SP HA KICK DASH TURN SAY TNECK
CATCH MOVE CHVIEW ARM MOVABLE EXP TAR COUNT FOCUS NONE TACKLE COLL BALL PLAYER
POST FOUL CHARGED CARD YELLOW

// see:
%token SEE _C _B _F _P _G _L _R _T _BB _FF _GG _PP GOALIE

// primitive types
%type <i> card_type
%type <i> int
%type <d> double
%type <s> string
%type <b> bool
%type <i> play_mode
%type <i> target_type
%type <i> col_type
%type <i> side

// complex types
%type <f> flag_name
%type <l> line_name

%%

start: init  | server_param  | player_param | player_type | sense_body | see;

bool:	_0 {$$ = false;} | _1 {$$=true;};
int:	INTEGER {$$ = atoi(d_scanner->matched().c_str());} |
        bool {$$ = $1? 1 : 0;} |
        _10 { $$ = 10; } |
        _20 { $$ = 20; }|
        _30 { $$ = 30; }|
        _40 { $$ = 40; }|
        _50 { $$ = 50; };
double:	DOUBLE {$$ = atof(d_scanner->matched().c_str());} |
        int {$$ = static_cast<double>($1);} ;
string:	STRING {$$ = new std::string(d_scanner->matched().c_str());} ;

init:   LP INIT side double play_mode RP {parent->model.play_mode = (Model::play_mode_type)$5;
                               cout << "seen init" << parent->model.play_mode << endl;
                               this->ACCEPT();};
play_mode:  PM_BKO   {$$ = Model::before_kick_off ;}|
            PM_PO    {$$ = Model::play_on ;}|
            PM_TO    {$$ = Model::time_over ;}|
            PM_KOL   {$$ = Model::kick_off_l ;}|
            PM_KOR   {$$ = Model::kick_off_r ;}|
            PM_KIL   {$$ = Model::kick_in_l ;}|
            PM_KIR   {$$ = Model::kick_in_r ;}|
            PM_FKL   {$$ = Model::free_kick_l ;}|
            PM_FKR   {$$ = Model::free_kick_r ;}|
            PM_CKL   {$$ = Model::corner_kick_l ;}|
            PM_CKR   {$$ = Model::corner_kick_r ;}|
            PM_GKL   {$$ = Model::goal_kick_l ;}|
            PM_GKR   {$$ = Model::goal_kick_r ;}|
            PM_GOALL {$$ = Model::goal_l ;}|
            PM_GOALR {$$ = Model::goal_r ;}|
            PM_DB    {$$ = Model::drop_ball ;}|
            PM_OL    {$$ = Model::offside_l ;}|
            PM_OR    {$$ = Model::offside_r ;};

server_param:	LP SERVER
acd am bdr bp bam bd br bs bsm bsa bw cbc cp cal caw cm cadw cdefw cdelw ciw
cmd cmpc cmw crw cws co cop cwr cw cr das dpr dbt ed edt ein eit ei em eht es
fko fc fdp fe fkf fsp fwp fl fr glc gld gldir glf glfn glv gl gow gw gmm gg
ht hd hi hm im k kl kld kldir lkf klfn klg ks kw kow kpr kr krfl krfr km lf ldf
lt mbtp maxda mdp mgk mtp maxm maxna maxnm maxp minda mindp minm minna minnm
minp neh nnh oaas okm op och pamk pbsw pcmp pdx pmet pmgdx pnk prw prwa psw ptw
pso pam pd pr ps psm psmm pw ptb ptd p pfl pfr prof pgk qs qsl rm rd rdt ri
rmin rs rcp sccm scms sms sm ss svs sbs sdr sims sdf sotflt sotfrt sc sim smax
sgl sgr sbv smics smod so sso tbd tc td te tpr trf tw tan tls trs tlc tld tldir
tlf tlfn tl uo v va vd wa wd wf wn wr wra RP {cout << "seen server_param" << endl;
                                              this->ACCEPT();};
/*|
LP SERVER
acd bdr bp bam bd br bs bsm bsa bw cbc cp cal caw cm cadw cdefw cdelw ciw
cmd cmpc cmw crw cws co cop cwr cw cr das dpr dbt ed edt ein eit ei em eht es
fko fc fdp fe fkf fsp fwp fl fr glc gld gldir glf glfn glv gl gow gw gmm gg
ht hd hi hm im k kl kld kldir lkf klfn klg ks kw kow kpr kr krfl krfr km lf ldf
lt mbtp maxda mdp mgk mtp maxm maxna maxnm maxp minda mindp minm minna minnm
minp neh nnh oaas okm op och pamk pbsw pcmp pdx pmet pmgdx pnk prw prwa psw ptw
pso pam pd pr ps psm psmm pw ptb ptd p pfl pfr prof pgk qs qsl rm rd rdt ri
rmin rs rcp sccm scms sms sm ss svs sbs sdr sims sdf sotflt sotfrt sc sim smax
sgl sgr sbv smics smod so sso tbd tc td te tpr trf tw tan tls trs tlc tld tldir
tlf tlfn tl uo v va vd wa wd wf wn wr wra RP {cout << "end of server_param version x" << endl;}*/

acd:	LP ACD double RP {parent->model.server.audio_cut_dist = $3; } ;
am:	LP AM bool RP {parent->model.server.auto_mode = $3;}; // not in 8
bdr:	LP BDR double RP {parent->model.server.back_dash_rate = $3;} ;
bp:	LP BP double RP {parent->model.server.back_passes = static_cast<bool>($3);} ;
bam:	LP BAM double RP {parent->model.server.ball_accel_max = $3;} ;
bd:	LP BD double RP {parent->model.server.ball_decay = $3;} ;
br:	LP BR double RP {parent->model.server.ball_rand = $3;} ;
bs:	LP BS double RP {parent->model.server.ball_size = $3;} ;
bsm:	LP BSM double RP {parent->model.server.ball_speed_max = $3;} ;
bsa:	LP BSA double RP {parent->model.server.ball_stuck_area = $3;} ;
bw:	LP BW double RP {parent->model.server.ball_weight = $3;} ;
cbc:	LP CBC int RP {parent->model.server.catch_ban_cycle = $3; } ;
cp:	LP CP double RP {parent->model.server.catch_probability = $3;} ;
cal:	LP CAL double RP {parent->model.server.catchable_area_l = $3;} ;
caw:	LP CAW double RP {parent->model.server.catchable_area_w = $3;} ;
cm:	LP CM double RP {parent->model.server.ckick_margin = $3;} ;
cadw:	LP CADW int RP {parent->model.server.clang_advice_win = $3;} ;
cdefw:	LP CDEFW int RP {parent->model.server.clang_define_win = $3; } ;
cdelw:	LP CDELW int RP {parent->model.server.clang_del_win = $3; } ;
ciw:	LP CIW int RP {parent->model.server.clang_info_win = $3; } ;
cmd:	LP CMD int RP {parent->model.server.clang_mess_delay = $3; } ;
cmpc:	LP CMPC int RP {parent->model.server.clang_mess_per_cycle = $3; } ;
cmw:	LP CMW int RP {parent->model.server.clang_meta_win = $3; } ;
crw:	LP CRW int RP {parent->model.server.clang_rule_win = $3; } ;
cws:	LP CWS int RP {parent->model.server.clang_win_size = $3; } ;
co:	LP CO double RP {parent->model.server.coach = ($3==0?false:true);} ;
cop:	LP COP int RP {parent->model.server.coach_port = $3; } ;
cwr:	LP CWR double RP {parent->model.server.coach_w_referee = ($3==0?false:true);} ;
cw:	LP CW int RP {parent->model.server.connect_wait = $3; }; // not in version 8
cr:	LP CR double RP {parent->model.server.control_radius = $3;} ;
das:	LP DAS double RP {parent->model.server.dash_angle_step = $3;} ;
dpr:	LP DPR double RP {parent->model.server.dash_power_rate = $3;} ;
pt_dpr:	LP DPR double RP {currentType->dash_power_rate = ($3);} ;
dbt:	LP DBT int RP {parent->model.server.drop_ball_time = $3; } ;
ed:	LP ED double RP {parent->model.server.effort_dec = ($3);} ;
edt:	LP EDT double RP {parent->model.server.effort_dec_thr = ($3);} ;
ein:	LP EIN double RP {parent->model.server.effort_inc = ($3);} ;
eit:	LP EIT double RP {parent->model.server.effort_inc_thr = ($3);} ;
ei:	LP EI double RP {parent->model.server.effort_init = ($3);} ;
em:	LP EM double RP {parent->model.server.effort_min = ($3);} ;
pt_emx:	LP EMAX double RP {currentType->effort_max = ($3);} ;
pt_emi:	LP EM double RP {currentType->effort_min = ($3);} ;
eht:	LP EHT int RP {parent->model.server.extra_half_time = $3; } ;
es:	LP ES double RP {parent->model.server.extra_stamina = ($3);} ;
pt_es:	LP ES double RP {currentType->extra_stamina = ($3);} ;
fko:	LP FKO double RP {parent->model.server.forbid_kick_off_offside = static_cast<bool>($3);} ;
fc:	LP FC int RP {parent->model.server.foul_cycles = $3; } ;
fdp:	LP FDP double RP {parent->model.server.foul_detect_probability = $3;} ;
pt_fdp:	LP FDP double RP {currentType->foul_detect_probability = $3;} ;
fe:	LP FE double RP {parent->model.server.foul_exponent = $3;} ;
fkf:	LP FKF double RP {parent->model.server.free_kick_faults = static_cast<bool>($3);} ;
fsp:	LP FSP double RP {parent->model.server.freeform_send_period = static_cast<unsigned int>($3);} ;
fwp:	LP FWP double RP {parent->model.server.freeform_wait_period = static_cast<unsigned int>($3);} ;
fl:	LP FL int RP {parent->model.server.fullstate_l = $3; } ;
fr:	LP FR int RP {parent->model.server.fullstate_r = $3; } ;
glc:	LP GLC int RP {parent->model.server.game_log_compression = $3; } ;
gld:	LP GLD int RP {parent->model.server.game_log_dated = $3; } ;
gldir:	LP GLDIR string RP {parent->model.server.game_log_dir = *($3);} ;
glf:	LP GLF double RP {parent->model.server.game_log_fixed= static_cast<bool>($3);} ;
glfn:	LP GLFN string RP {parent->model.server.game_log_fixed_name = *($3);} ;
glv:	LP GLV int RP {parent->model.server.game_log_version = $3; } ;
gl:	LP GL double RP {parent->model.server.game_logging = static_cast<bool>($3);} ;
gow:	LP GOW double RP {parent->model.server.game_over_wait = $3; }; // not in version 8
gw:	LP GW double RP {parent->model.server.goal_width = ($3);} ;
gmm:	LP GMM int RP {parent->model.server.goalie_max_moves = $3; } ;
gg:	LP GG double RP {parent->model.server.golden_goal = static_cast<bool>($3);} ;
ht:	LP HT int RP {parent->model.server.half_time = $3; } ;
hd:	LP HD double RP {parent->model.server.hear_decay = static_cast<unsigned int>($3);} ;
hi:	LP HI double RP {parent->model.server.hear_inc = static_cast<unsigned int>($3);} ;
hm:	LP HM double RP {parent->model.server.hear_max = static_cast<unsigned int>($3);} ;
im:	LP IM double RP {parent->model.server.inertia_moment = ($3);} ;
pt_im:	LP IM double RP {currentType->inertia_moment = ($3);} ;
k:	LP K double RP {parent->model.server.keepaway = static_cast<bool>($3);} ;
kl:	LP KL double RP {parent->model.server.keepaway_length = ($3);} ;
kld:	LP KLD double RP {parent->model.server.keepaway_log_dated = static_cast<bool>($3);} ;
kldir:	LP KLDIR string RP {parent->model.server.keepaway_log_dir = *($3);} ;
lkf:	LP LKF double RP {parent->model.server.keepaway_log_fixed = static_cast<bool>($3);} ;
klfn:	LP KLFN string RP {parent->model.server.keepaway_log_fixed_name = *($3);} ;
klg:	LP KLG double RP {parent->model.server.keepaway_logging = static_cast<bool>($3);} ;
ks:	LP KS int RP {parent->model.server.keepaway_start = $3; } ;
kw:	LP KW double RP {parent->model.server.keepaway_width = ($3);} ;
kow:	LP KOW int RP {parent->model.server.kick_off_wait = $3; } ;
kpr:	LP KPR double RP {parent->model.server.kick_power_rate = ($3);} ;
pt_kpr:	LP KPR double RP {currentType->kick_power_rate= ($3);} ;
kr:	LP KR double RP {parent->model.server.kick_rand = ($3);} ;
pt_kr:	LP KR double RP {currentType->kick_rand = ($3);} ;
krfl:	LP KRFL double RP {parent->model.server.kick_rand_factor_l = ($3);} ;
krfr:	LP KRFR double RP {parent->model.server.kick_rand_factor_r = ($3);} ;
km:	LP KM double RP {parent->model.server.kickable_margin = ($3);} ;
pt_km:	LP KM double RP {currentType->kickable_margin = ($3);} ;
lf:	LP LF string RP {parent->model.server.landmark_file = *($3);} ;
ldf:	LP LDF string RP {parent->model.server.log_date_format = *($3);} ;
lt:	LP LT int RP {parent->model.server.log_times = $3; } ;
mbtp:	LP MBTP double RP {parent->model.server.max_back_tackle_power = ($3);} ;
maxda:	LP MAXDA double RP {parent->model.server.max_dash_angle = ($3);} ;
mdp:	LP MDP double RP {parent->model.server.max_dash_power = ($3);} ;
mgk:	LP MGK int RP {parent->model.server.max_goal_kicks = $3; } ;
mtp:	LP MTP double RP {parent->model.server.max_tackle_power = ($3);} ;
maxm:	LP MAXM double RP {parent->model.server.maxmoment = ($3);} ;
maxna:	LP MAXNA double RP {parent->model.server.maxneckang = ($3);} ;
maxnm:	LP MAXNM double RP {parent->model.server.maxneckmoment = ($3);} ;
maxp:	LP MAXP double RP {parent->model.server.maxpower = ($3);} ;
minda:	LP MINDA double RP {parent->model.server.min_dash_angle = ($3);} ;
mindp:	LP MINDP double RP {parent->model.server.min_dash_power = ($3);} ;
minm:	LP MINM double RP {parent->model.server.minmoment = ($3);} ;
minna:	LP MINNA double RP {parent->model.server.minneckang = ($3);} ;
minnm:	LP MINNM double RP {parent->model.server.minneckmoment = ($3);} ;
minp:	LP MINP double RP {parent->model.server.minpower = ($3);} ;
neh:	LP NEH int RP {parent->model.server.nr_extra_halfs = $3; } ;
nnh:	LP NNH int RP {parent->model.server.nr_normal_halfs = $3; } ;
oaas:	LP OAAS double RP {parent->model.server.offside_active_area_size = ($3);} ;
okm:	LP OKM double RP {parent->model.server.offside_kick_margin = ($3);} ;
op:	LP OP int RP {parent->model.server.olcoach_port = $3; } ;
och:	LP OCH double RP {parent->model.server.old_coach_hear = static_cast<bool>($3);} ;
pamk:	LP PAMK double RP {parent->model.server.pen_allow_mult_kicks = static_cast<bool>($3);} ;
pbsw:	LP PBSW double RP {parent->model.server.pen_before_setup_wait = static_cast<bool>($3);} ;
pcmp:	LP PCMP double RP {parent->model.server.pen_coach_moves_players = static_cast<bool>($3);} ;
pdx:	LP PDX double RP {parent->model.server.pen_dist_x = ($3);} ;
pmet:	LP PMET int RP {parent->model.server.pen_max_extra_kicks = $3; } ;
pmgdx:	LP PMGDX int RP {parent->model.server.pen_max_goalie_dist_x = $3; } ;
pnk:	LP PNK int RP {parent->model.server.pen_nr_kicks = $3; } ;
prw:	LP PRW double RP {parent->model.server.pen_random_winner = static_cast<bool>($3);} ;
prwa:	LP PRWA int RP {parent->model.server.pen_ready_wait = $3; } ;
psw:	LP PSW int RP {parent->model.server.pen_setup_wait = $3; } ;
ptw:	LP PTW int RP {parent->model.server.pen_taken_wait = $3; } ;
pso:	LP PSO double RP {parent->model.server.penalty_shoot_outs = static_cast<bool>($3);} ;
pam:	LP PAM double RP {parent->model.server.player_accel_max = ($3);} ;
pd:	LP PD double RP {parent->model.server.player_decay = ($3);} ;
pt_pd:	LP PD double RP {currentType->player_decay= ($3);} ;
pr:	LP PR double RP {parent->model.server.player_rand = ($3);} ;
ps:	LP PS double RP {parent->model.server.player_size = ($3);} ;
pt_ps:	LP PS double RP {currentType->player_size = ($3);} ;
psm:	LP PSM double RP {parent->model.server.player_speed_max = ($3);} ;
pt_psm:	LP PSM double RP {currentType->player_speed_max = ($3);} ;
psmm:	LP PSMM double RP {parent->model.server.player_speed_max_min = ($3);} ;
pw:	LP PW double RP {parent->model.server.player_weight = ($3);} ;
ptb:	LP PTB int RP {parent->model.server.point_to_ban = $3; } ;
ptd:	LP PTD int RP {parent->model.server.point_to_duration = $3; } ;
p:	LP P int RP {parent->model.server.port = $3; } ;
pfl:	LP PFL double RP {parent->model.server.prand_factor_l = ($3);} ;
pfr:	LP PFR double RP {parent->model.server.prand_factor_r = ($3);} ;
prof:	LP PROF double RP {parent->model.server.profile = static_cast<bool>($3);} ;
pgk:	LP PGK double RP {parent->model.server.proper_goal_kicks = static_cast<bool>($3);} ;
qs:	LP QS double RP {parent->model.server.quantize_step = ($3);} ;
qsl:	LP QSL double RP {parent->model.server.quantize_step_l = ($3);} ;
rm:	LP RM double RP {parent->model.server.record_messages = static_cast<bool>($3);} ;
rd:	LP RD double RP {parent->model.server.recover_dec = ($3);} ;
rdt:	LP RDT double RP {parent->model.server.recover_dec_thr = ($3);} ;
ri:	LP RI double RP {parent->model.server.recover_init = ($3);} ;
rmin:	LP RMIN double RP {parent->model.server.recover_min = ($3);} ;
rs:	LP RS int RP {parent->model.server.recv_step = $3; } ;
rcp:	LP RCP double RP {parent->model.server.red_card_probability = ($3);} ;
sccm:	LP SCCM int RP {parent->model.server.say_coach_cnt_max = $3; } ;
scms:	LP SCMS int RP {parent->model.server.say_coach_msg_size = $3; } ;
sms:	LP SMS int RP {parent->model.server.say_msg_size = $3; } ;
sm:	LP SM double RP {parent->model.server.send_comms = static_cast<bool>($3);} ;
ss:	LP SS int RP {parent->model.server.send_step = $3; } ;
svs:	LP SVS int RP {parent->model.server.send_vi_step = $3; } ;
sbs:	LP SBS int RP {parent->model.server.sense_body_step = $3; } ;
sdr:	LP SDR double RP {parent->model.server.side_dash_rate = ($3);} ;
sims:	LP SIMS int RP {parent->model.server.simulator_step = $3; } ;
sdf:	LP SDF int RP {parent->model.server.slow_down_factor = $3; } ;
sotflt:	LP SOTFLT double RP {parent->model.server.slowness_on_top_for_left_team = ($3);} ;
sotfrt:	LP SOTFRT double RP {parent->model.server.slowness_on_top_for_right_team = ($3);} ;
sc:	LP SC double RP {parent->model.server.stamina_capacity = ($3);} ;
sim:	LP SIM double RP {parent->model.server.stamina_inc_max = ($3);} ;
pt_sim:	LP SIM double RP {currentType->stamina_inc_max = ($3);} ;
smax:	LP SMAX double RP {parent->model.server.stamina_max = ($3);};
sgl:	LP SGL int RP {parent->model.server.start_goal_l = $3; } ;
sgr:	LP SGR int RP {parent->model.server.start_goal_r = $3; } ;
sbv:	LP SBV double RP {parent->model.server.stopped_ball_vel = ($3);} ;
smics:	LP SMICS double RP {parent->model.server.synch_micro_sleep = static_cast<unsigned int>($3);} ;
smod:	LP SMOD double RP {parent->model.server.synch_mode = static_cast<bool>($3);} ;
so:	LP SO double RP {parent->model.server.synch_offset = $3; } ;
sso:	LP SSO double RP {parent->model.server.synch_see_offset = $3; } ;
tbd:	LP TBD double RP {parent->model.server.tackle_back_dist = ($3);} ;
tc:	LP TC double RP {parent->model.server.tackle_cycles = static_cast<unsigned int>($3);} ;
td:	LP TD double RP {parent->model.server.tackle_dist = ($3);} ;
te:	LP TE double RP {parent->model.server.tackle_exponent = ($3);} ;
tpr:	LP TPR double RP {parent->model.server.tackle_power_rate = ($3);} ;
trf:	LP TRF double RP {parent->model.server.tackle_rand_factor = ($3);} ;
tw:	LP TW double RP {parent->model.server.tackle_width = ($3);} ;
tan:	LP TAN double RP {parent->model.server.team_actuator_noise = static_cast<bool>($3);} ;
tls:	LP TLS string RP {parent->model.server.team_l_start = *($3);} ;
trs:	LP TRS string RP {parent->model.server.team_r_start = *($3);} ;
tlc:	LP TLC int RP {parent->model.server.text_log_compression = $3; } ;
tld:	LP TLD int RP {parent->model.server.text_log_dated = $3; } ;
tldir:	LP TLDIR string RP {parent->model.server.text_log_dir = *($3);} ;
tlf:	LP TLF int RP {parent->model.server.text_log_fixed = $3; } ;
tlfn:	LP TLFN string RP {parent->model.server.text_log_fixed_name = *($3);} ;
tl:	LP TL double RP {parent->model.server.text_logging = static_cast<bool>($3);} ;
uo:	LP UO double RP {parent->model.server.use_offside = static_cast<bool>($3);} ;
v:	LP V bool RP {parent->model.server.verbose = $3;} ;
va:	LP VA double RP {parent->model.server.visible_angle = ($3);} ;
vd:	LP VD double RP {parent->model.server.visible_distance = ($3);} ;
wa:	LP WA double RP {parent->model.server.wind_ang = ($3);} ;
wd:	LP WD double RP {parent->model.server.wind_dir = ($3);} ;
wf:	LP WF double RP {parent->model.server.wind_force = ($3);} ;
wn:	LP WN double RP {parent->model.server.wind_none = static_cast<bool>($3);} ;
wr:	LP WR double RP {parent->model.server.wind_rand = ($3);} ;
wra:	LP WRA double RP {parent->model.server.wind_random = ($3);} ;

player_param: LP PP amdt calsmax calsmin dprdmax dprdmin emaxdf emindf esdmax esdmin fdpdf imdf
kprdmax kprdmin kprdf kmdmax kmdmin ndprdmax ndprdmin nsimaxdf pddmax pddmin
psdf psmaxdmax psmaxdmin pt ptm rans simaxdf submax RP {cout << "seen player_param" << endl; this->ACCEPT();};

player_type: LP PTY id pt_psm pt_sim pt_pd pt_im pt_dpr pt_ps pt_km pt_kr pt_es
pt_emx pt_emi pt_kpr pt_fdp pt_cals RP {cout << "seen player_type " << currentType->id << endl; this->ACCEPT();};

amdt:		LP AMDT double RP {parent->model.player.allow_mult_default_type = ($3);};
calsmax:	LP CALSMAX double RP {parent->model.player.catchable_area_l_stretch_max = ($3);};
pt_cals:	LP CALS double RP {currentType->catchable_area_l_stretch = ($3);};
calsmin:	LP CALSMIN double RP {parent->model.player.catchable_area_l_stretch_min = ($3);};
dprdmax:	LP DPRDMAX double RP {parent->model.player.dash_power_rate_delta_max = ($3);};
dprdmin:	LP DPRDMIN double RP {parent->model.player.dash_power_rate_delta_min = ($3);};
emaxdf:		LP EMAXDF double RP {parent->model.player.effort_max_delta_factor = ($3);};
emindf:		LP EMINDF double RP {parent->model.player.effort_min_delta_factor = ($3);};
esdmax:		LP ESDMAX double RP {parent->model.player.extra_stamina_delta_max = ($3);};
esdmin:		LP ESDMIN double RP {parent->model.player.extra_stamina_delta_min = ($3);};
fdpdf:		LP FDPDF double RP {parent->model.player.foul_detect_probability_delta_factor = ($3);};
imdf:		LP IMDF double RP {parent->model.player.inertia_moment_delta_factor = ($3);};
kprdmax:	LP KPRDMAX double RP {parent->model.player.kick_power_rate_delta_max = ($3);};
kprdmin:	LP KPRDMIN double RP {parent->model.player.kick_power_rate_delta_min = ($3);};
kprdf:		LP KPRDF double RP {parent->model.player.kick_rand_delta_factor = ($3);};
kmdmax:		LP KMDMAX double RP {parent->model.player.kickable_margin_delta_max = ($3);};
kmdmin:		LP KMDMIN double RP {parent->model.player.kickable_margin_delta_min = ($3);};
ndprdmax:	LP NDPRDMAX double RP {parent->model.player.new_dash_power_rate_delta_max = ($3);};
ndprdmin:	LP NDPRDMIN double RP {parent->model.player.new_dash_power_rate_delta_min = ($3);};
nsimaxdf:	LP NSIMAXDF double RP {parent->model.player.new_stamina_inc_max_delta_factor = ($3);};
pddmax:		LP PDDMAX double RP {parent->model.player.player_decay_delta_max = ($3);};
pddmin:		LP PDDMIN double RP {parent->model.player.player_decay_delta_min = ($3);};
psdf:		LP PSDF double RP {parent->model.player.player_size_delta_factor = ($3);};
psmaxdmax:	LP PSMAXDMAX double RP {parent->model.player.player_speed_max_delta_max = ($3);};
psmaxdmin:	LP PSMAXDMIN double RP {parent->model.player.player_speed_max_delta_min = ($3);};
pt:		LP PT int RP {parent->model.player.player_types = $3; };
ptm:		LP PTM int RP {parent->model.player.pt_max = $3; };
rans:		LP RANS int RP {parent->model.player.random_seed = $3; };
simaxdf:	LP SIMAXDF double RP {parent->model.player.stamina_inc_max_delta_factor = ($3);};
submax: 	LP SUBMAX int RP {parent->model.player.subs_max = $3; };

id:		LP ID int RP {
    t_player_type x;
    parent->model.player_types.push_back(x);
    currentType = parent->model.player_types.rbegin();
    currentType->id = $3;
};

sense_body:	LP SEN double vm st sp ha kick dash turn say tneck catch move chview
		arm focus tackle collision foul RP {cout << "sense_body" << endl;};
vm:		LP VM v_q v_w RP {};
v_q:		VQ_H {parent->model.body.view_mode.quality = t_view_mode::high;} |
		VQ_L {parent->model.body.view_mode.quality = t_view_mode::low;};
v_w:		VW_NO {parent->model.body.view_mode.width = t_view_mode::normal_w;} |
		VW_NA {parent->model.body.view_mode.width = t_view_mode::narrow;} |
		VW_WI {parent->model.body.view_mode.width = t_view_mode::wide;};
st:		LP ST double double double RP
                {
                    parent->model.body.stamina.stamina = $3;
                    parent->model.body.stamina.effort = $4;
                    parent->model.body.stamina.capacity = $5;
                };
sp:		LP SP double double RP {parent->model.body.speed.x = $3; parent->model.body.speed.y = $4;};
ha:		LP HA int RP {parent->model.body.head_angle = $3;};
kick:		LP KICK int RP {parent->model.body.kick = $3;};
dash:		LP DASH int RP {parent->model.body.dash = $3;};
turn:		LP TURN int RP {parent->model.body.turn = $3;};
say:		LP SAY int RP {parent->model.body.say = $3;};
tneck:		LP TNECK int RP {parent->model.body.turn_neck = $3;};
catch:		LP CATCH int RP {parent->model.body.catch_ = $3;};
move:		LP MOVE int RP {parent->model.body.move = $3;};
chview:		LP CHVIEW int RP {parent->model.body.change_view = $3;};

arm:		LP ARM movable expires target count RP;
movable:	LP MOVABLE int RP {parent->model.body.arm.movable = $3;};
expires:	LP EXP int RP {parent->model.body.arm.expires = $3;};
target:		LP TAR double double RP {parent->model.body.arm.target = Point($3,$4);};
count:		LP COUNT int RP {parent->model.body.arm.count = $3;};

focus:		LP FOCUS f_target f_count RP;
f_target:	LP TAR target_type RP {parent->model.body.focus.type = static_cast<t_focus::focus_type>($3);};
f_count:	LP COUNT int RP {};
target_type:	_L {$$ = t_focus::l;} |
                _R {$$ = t_focus::r;} |
                NONE {$$ = t_focus::none;};

tackle:		LP TACKLE t_expires t_count RP;
t_expires:	LP EXP int RP {parent->model.body.tackle.expires = $3;};
t_count:	LP COUNT int RP {parent->model.body.tackle.count = $3;};

collision:	LP COLL col_type RP {parent->model.body.collition.type = static_cast<t_collition::collition_type>($3);};
col_type:	NONE {$$ = t_collition::none;} |
                BALL {$$ = t_collition::ball;} |
                PLAYER {$$ = t_collition::player;} |
                POST {$$ = t_collition::post;};

foul:		LP FOUL charged card RP;
charged:	LP CHARGED int RP {parent->model.body.foul.charged = $3;};
card:		LP CARD card_type RP {parent->model.body.foul.card = static_cast<t_foul::card_type>($3);};
card_type:	NONE {$$ = t_foul::none;} |
                YELLOW {$$ = t_foul::yellow;};

see:		LP SEE int objects RP {cout << "seen see" << endl; this->ACCEPT();};
objects:	object objects |
		object ;
object:		o_ball |
		o_player |
		o_goal |
                o_flag |
                o_line |
                o_unknown;

o_ball:		LP LP _B RP double double RP
		{
		    //parent->model.visual.add(new Ball($5, $6));
		} |
		LP LP _B RP double double double double RP
		{
		    //parent->model.visual.add(new Flag2($5, $6, $7, $8, "(b)"));
		};
o_player:	LP LP _P string int RP double double double double double double RP
		{
		    //parent->model.visual.add(new Player1($7, $8, $9, $10.d, $11.d, $12.d, *$4, $5));
		} |
		LP LP _P string int GOALIE RP double double double double double double RP
		{
		    //parent->model.visual.add(new Player1($7, $8, $9, $10.d, $11.d, $12.d, *$4, $5, true));
		} |
		LP LP _P string RP double double RP {} |
		LP LP _P RP double double RP {};
o_goal:		LP LP _G side RP double double RP {} |
		LP LP _G side RP double double double double RP {};
o_flag:		LP LP flag_name RP double double RP
		{
                    parent->model.visual.add(new Flag($3->s, $3->x, $3->y, $5, $6));
		}|
		LP LP flag_name RP double double double double RP 
                {
                    parent->model.visual.add(new Flag2($3->s, $3->x, $3->y, $5, $6, $7, $8));
                };
o_unknown:	LP LP unknown RP double double RP
                {
                }|
                LP LP unknown RP double double double double RP
                {
                };
o_line:		LP LP line_name RP double double RP { new Line($3->p, $3->o, $5, $6); };
flag_name:	_F _C { $$ = new flag_data(string("fc"),0,0); }|
		_F _L _T { $$ = new flag_data("flt",-52.50,-34.00); } |
		_F _L _B { $$ = new flag_data("flb",-52.50,+34.00); } |
		_F _R _T { $$ = new flag_data("frt",+52.50,-34.00); } |
		_F _R _B { $$ = new flag_data("frb",+52.50,+34.00); } |
		_F _C _T { $$ = new flag_data("fct",+00.00,-34.00); } |
		_F _C _B { $$ = new flag_data("fcb",+00.00,+34.00); } |
		_F _P _L _T { $$ = new flag_data("fplt",-36.00,-20.15); } |
		_F _P _L _C { $$ = new flag_data("fplc",-36.00,+00.00); } |
		_F _P _L _B { $$ = new flag_data("fplb",-36.00,+20.15); } |
		_F _P _R _T { $$ = new flag_data("fprt",+36.00,-20.15); } |
		_F _P _R _C { $$ = new flag_data("fprc",+36.00,+00.00); } |
		_F _P _R _B { $$ = new flag_data("fprb",+36.00,+20.15); } |
		_F _G _L _T { $$ = new flag_data("fglt",-52.50,-07.00); }|
		_F _G _L _B { $$ = new flag_data("fglb",-52.50,+07.00); }|
		_F _G _R _T { $$ = new flag_data("fgrt",+52.50,-07.00); }|
		_F _G _R _B { $$ = new flag_data("fgrb",+52.50,+07.00); }|
		_F _L _0 { $$ = new flag_data("fl0",-57.50,+00.00); }|
		_F _R _0 { $$ = new flag_data("fr0",+57.50,+00.00); }|
		_F _T _0 { $$ = new flag_data("ft0",+00.00,-39.00); }|
		_F _B _0 { $$ = new flag_data("fb0",+00.00,+39.00); }|
		_F _T _L _10 { $$ = new flag_data("ftl10",-10.00,-39.00); }|
		_F _T _L _20 { $$ = new flag_data("ftl20",-20.00,-39.00); }|
		_F _T _L _30 { $$ = new flag_data("ftl30",-30.00,-39.00); }|
		_F _T _L _40 { $$ = new flag_data("ftl40",-40.00,-39.00); }|
		_F _T _L _50 { $$ = new flag_data("ftl50",-50.00,-39.00); }|
		_F _T _R _10 { $$ = new flag_data("ftr10",+10.00,-39.00); }|
		_F _T _R _20 { $$ = new flag_data("ftr20",+20.00,-39.00); }|
		_F _T _R _30 { $$ = new flag_data("ftr30",+30.00,-39.00); }|
		_F _T _R _40 { $$ = new flag_data("ftr40",+40.00,-39.00); }|
		_F _T _R _50 { $$ = new flag_data("ftr50",+50.00,-39.00); }|
		_F _B _L _10 { $$ = new flag_data("fbl10",-10.00,+39.00); }|
		_F _B _L _20 { $$ = new flag_data("fbl20",-20.00,+39.00); }|
		_F _B _L _30 { $$ = new flag_data("fbl30",-30.00,+39.00); }|
		_F _B _L _40 { $$ = new flag_data("fbl40",-40.00,+39.00); }|
		_F _B _L _50 { $$ = new flag_data("fbl50",-50.00,+39.00); }|
		_F _B _R _10 { $$ = new flag_data("fbr10",+10.00,+39.00); }|
		_F _B _R _20 { $$ = new flag_data("fbr20",+20.00,+39.00); }|
		_F _B _R _30 { $$ = new flag_data("fbr30",+30.00,+39.00); }|
		_F _B _R _40 { $$ = new flag_data("fbr40",+40.00,+39.00); }|
		_F _B _R _50 { $$ = new flag_data("fbr50",+50.00,+39.00); }|
		_F _L _T _10 { $$ = new flag_data("flt10",-57.50,-10.00); } |
		_F _L _T _20 { $$ = new flag_data("flt20",-57.50,-20.00); } |
		_F _L _T _30 { $$ = new flag_data("flt30",-57.50,-30.00); } |
		_F _L _B _10 { $$ = new flag_data("flb10",-57.50,+10.00); } |
		_F _L _B _20 { $$ = new flag_data("flb20",-57.50,+20.00); } |
		_F _L _B _30 { $$ = new flag_data("flb30",-57.50,+30.00); } |
		_F _R _T _10 { $$ = new flag_data("frt10",+57.50,-10.00); } |
		_F _R _T _20 { $$ = new flag_data("frt20",+57.50,-20.00); } |
		_F _R _T _30 { $$ = new flag_data("frt30",+57.50,-30.00); } |
		_F _R _B _10 { $$ = new flag_data("frb10",+57.50,+10.00); } |
		_F _R _B _20 { $$ = new flag_data("frb20",+57.50,+20.00); } |
		_F _R _B _30 { $$ = new flag_data("frb30",+57.50,+30.00); } ;
line_name:	_L _L { $$ = new line_data(-52.50, Line::Horizontal); } |
                _L _R { $$ = new line_data(+52.50, Line::Horizontal); } |
                _L _T { $$ = new line_data(-34.00, Line::Vertical); } |
                _L _B { $$ = new line_data(+34.00, Line::Vertical); };
side:		_L { $$ = 0; } |
                _R { $$ = 1; };
unknown:	_BB { } |
                _FF {  } |
                _GG {} |
                _PP { } ;
