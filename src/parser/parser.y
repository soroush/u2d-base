%scanner                ./Scanner.h
%scanner-token-function d_scanner.lex()

%union{
double		d;
int		i;
bool		b;
std::string*	s;
}

%token <d> 	DOUBLE
%token <i> 	INTEGER
%token <s> 	STRING

%token INIT
%token SERVER
%token LP
%token RP

//global tokens:
_0 _1

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

%%

start: init  | server_param  | player_param | player_type | sense_body | see;

bool:	_0 {$$.b = false;} | _1 {$$.b=true;};
int:	INTEGER {$$.i = atoi(d_scanner->matched().c_str());} |
	bool {$$.i = $1.b? 1 : 0;};
double:	DOUBLE {$$.d = atof(d_scanner->matched().c_str());} |
	int {$$.d = static_cast<double>($1.i);} ;
string:	STRING {$$.s = new std::string(d_scanner->matched().c_str());} ;

init:   LP INIT side double play_mode RP {parent->model.play_mode = (Model::play_mode_type)$5.i;
                               cout << "seen init" << parent->model.play_mode << endl;
                               this->ACCEPT();};
play_mode:  PM_BKO   {$$.i = Model::before_kick_off ;}|
            PM_PO    {$$.i = Model::play_on ;}|
            PM_TO    {$$.i = Model::time_over ;}|
            PM_KOL   {$$.i = Model::kick_off_l ;}|
            PM_KOR   {$$.i = Model::kick_off_r ;}|
            PM_KIL   {$$.i = Model::kick_in_l ;}|
            PM_KIR   {$$.i = Model::kick_in_r ;}|
            PM_FKL   {$$.i = Model::free_kick_l ;}|
            PM_FKR   {$$.i = Model::free_kick_r ;}|
            PM_CKL   {$$.i = Model::corner_kick_l ;}|
            PM_CKR   {$$.i = Model::corner_kick_r ;}|
            PM_GKL   {$$.i = Model::goal_kick_l ;}|
            PM_GKR   {$$.i = Model::goal_kick_r ;}|
            PM_GOALL {$$.i = Model::goal_l ;}|
            PM_GOALR {$$.i = Model::goal_r ;}|
            PM_DB    {$$.i = Model::drop_ball ;}|
            PM_OL    {$$.i = Model::offside_l ;}|
            PM_OR    {$$.i = Model::offside_r ;};

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

acd:	LP ACD double RP {parent->model.server.audio_cut_dist = $3.d; } ;
am:	LP AM bool RP {parent->model.server.auto_mode = $3.b;}; // not in 8
bdr:	LP BDR double RP {parent->model.server.back_dash_rate = $3.d;} ;
bp:	LP BP double RP {parent->model.server.back_passes = static_cast<bool>($3.d);} ;
bam:	LP BAM double RP {parent->model.server.ball_accel_max = $3.d;} ;
bd:	LP BD double RP {parent->model.server.ball_decay = $3.d;} ;
br:	LP BR double RP {parent->model.server.ball_rand = $3.d;} ;
bs:	LP BS double RP {parent->model.server.ball_size = $3.d;} ;
bsm:	LP BSM double RP {parent->model.server.ball_speed_max = $3.d;} ;
bsa:	LP BSA double RP {parent->model.server.ball_stuck_area = $3.d;} ;
bw:	LP BW double RP {parent->model.server.ball_weight = $3.d;} ;
cbc:	LP CBC int RP {parent->model.server.catch_ban_cycle = $3.i; } ;
cp:	LP CP double RP {parent->model.server.catch_probability = $3.d;} ;
cal:	LP CAL double RP {parent->model.server.catchable_area_l = $3.d;} ;
caw:	LP CAW double RP {parent->model.server.catchable_area_w = $3.d;} ;
cm:	LP CM double RP {parent->model.server.ckick_margin = $3.d;} ;
cadw:	LP CADW int RP {parent->model.server.clang_advice_win = $3.i;} ;
cdefw:	LP CDEFW int RP {parent->model.server.clang_define_win = $3.i; } ;
cdelw:	LP CDELW int RP {parent->model.server.clang_del_win = $3.i; } ;
ciw:	LP CIW int RP {parent->model.server.clang_info_win = $3.i; } ;
cmd:	LP CMD int RP {parent->model.server.clang_mess_delay = $3.i; } ;
cmpc:	LP CMPC int RP {parent->model.server.clang_mess_per_cycle = $3.i; } ;
cmw:	LP CMW int RP {parent->model.server.clang_meta_win = $3.i; } ;
crw:	LP CRW int RP {parent->model.server.clang_rule_win = $3.i; } ;
cws:	LP CWS int RP {parent->model.server.clang_win_size = $3.i; } ;
co:	LP CO double RP {parent->model.server.coach = ($3.d==0?false:true);} ;
cop:	LP COP int RP {parent->model.server.coach_port = $3.i; } ;
cwr:	LP CWR double RP {parent->model.server.coach_w_referee = ($3.d==0?false:true);} ;
cw:	LP CW int RP {parent->model.server.connect_wait = $3.i; }; // not in version 8
cr:	LP CR double RP {parent->model.server.control_radius = $3.d;} ;
das:	LP DAS double RP {parent->model.server.dash_angle_step = $3.d;} ;
dpr:	LP DPR double RP {parent->model.server.dash_power_rate = $3.d;} ;
pt_dpr:	LP DPR double RP {currentType->dash_power_rate = ($3.d);} ;
dbt:	LP DBT int RP {parent->model.server.drop_ball_time = $3.i; } ;
ed:	LP ED double RP {parent->model.server.effort_dec = ($3.d);} ;
edt:	LP EDT double RP {parent->model.server.effort_dec_thr = ($3.d);} ;
ein:	LP EIN double RP {parent->model.server.effort_inc = ($3.d);} ;
eit:	LP EIT double RP {parent->model.server.effort_inc_thr = ($3.d);} ;
ei:	LP EI double RP {parent->model.server.effort_init = ($3.d);} ;
em:	LP EM double RP {parent->model.server.effort_min = ($3.d);} ;
pt_emx:	LP EMAX double RP {currentType->effort_max = ($3.d);} ;
pt_emi:	LP EM double RP {currentType->effort_min = ($3.d);} ;
eht:	LP EHT int RP {parent->model.server.extra_half_time = $3.i; } ;
es:	LP ES double RP {parent->model.server.extra_stamina = ($3.d);} ;
pt_es:	LP ES double RP {currentType->extra_stamina = ($3.d);} ;
fko:	LP FKO double RP {parent->model.server.forbid_kick_off_offside = static_cast<bool>($3.d);} ;
fc:	LP FC int RP {parent->model.server.foul_cycles = $3.i; } ;
fdp:	LP FDP double RP {parent->model.server.foul_detect_probability = $3.d;} ;
pt_fdp:	LP FDP double RP {currentType->foul_detect_probability = $3.d;} ;
fe:	LP FE double RP {parent->model.server.foul_exponent = $3.d;} ;
fkf:	LP FKF double RP {parent->model.server.free_kick_faults = static_cast<bool>($3.d);} ;
fsp:	LP FSP double RP {parent->model.server.freeform_send_period = static_cast<unsigned int>($3.d);} ;
fwp:	LP FWP double RP {parent->model.server.freeform_wait_period = static_cast<unsigned int>($3.d);} ;
fl:	LP FL int RP {parent->model.server.fullstate_l = $3.i; } ;
fr:	LP FR int RP {parent->model.server.fullstate_r = $3.i; } ;
glc:	LP GLC int RP {parent->model.server.game_log_compression = $3.i; } ;
gld:	LP GLD int RP {parent->model.server.game_log_dated = $3.i; } ;
gldir:	LP GLDIR string RP {parent->model.server.game_log_dir = *($3.s);} ;
glf:	LP GLF double RP {parent->model.server.game_log_fixed= static_cast<bool>($3.d);} ;
glfn:	LP GLFN string RP {parent->model.server.game_log_fixed_name = *($3.s);} ;
glv:	LP GLV int RP {parent->model.server.game_log_version = $3.i; } ;
gl:	LP GL double RP {parent->model.server.game_logging = static_cast<bool>($3.d);} ;
gow:	LP GOW double RP {parent->model.server.game_over_wait = $3.i; }; // not in version 8
gw:	LP GW double RP {parent->model.server.goal_width = ($3.d);} ;
gmm:	LP GMM int RP {parent->model.server.goalie_max_moves = $3.i; } ;
gg:	LP GG double RP {parent->model.server.golden_goal = static_cast<bool>($3.d);} ;
ht:	LP HT int RP {parent->model.server.half_time = $3.i; } ;
hd:	LP HD double RP {parent->model.server.hear_decay = static_cast<unsigned int>($3.d);} ;
hi:	LP HI double RP {parent->model.server.hear_inc = static_cast<unsigned int>($3.d);} ;
hm:	LP HM double RP {parent->model.server.hear_max = static_cast<unsigned int>($3.d);} ;
im:	LP IM double RP {parent->model.server.inertia_moment = ($3.d);} ;
pt_im:	LP IM double RP {currentType->inertia_moment = ($3.d);} ;
k:	LP K double RP {parent->model.server.keepaway = static_cast<bool>($3.d);} ;
kl:	LP KL double RP {parent->model.server.keepaway_length = ($3.d);} ;
kld:	LP KLD double RP {parent->model.server.keepaway_log_dated = static_cast<bool>($3.d);} ;
kldir:	LP KLDIR string RP {parent->model.server.keepaway_log_dir = *($3.s);} ;
lkf:	LP LKF double RP {parent->model.server.keepaway_log_fixed = static_cast<bool>($3.d);} ;
klfn:	LP KLFN string RP {parent->model.server.keepaway_log_fixed_name = *($3.s);} ;
klg:	LP KLG double RP {parent->model.server.keepaway_logging = static_cast<bool>($3.d);} ;
ks:	LP KS int RP {parent->model.server.keepaway_start = $3.i; } ;
kw:	LP KW double RP {parent->model.server.keepaway_width = ($3.d);} ;
kow:	LP KOW int RP {parent->model.server.kick_off_wait = $3.i; } ;
kpr:	LP KPR double RP {parent->model.server.kick_power_rate = ($3.d);} ;
pt_kpr:	LP KPR double RP {currentType->kick_power_rate= ($3.d);} ;
kr:	LP KR double RP {parent->model.server.kick_rand = ($3.d);} ;
pt_kr:	LP KR double RP {currentType->kick_rand = ($3.d);} ;
krfl:	LP KRFL double RP {parent->model.server.kick_rand_factor_l = ($3.d);} ;
krfr:	LP KRFR double RP {parent->model.server.kick_rand_factor_r = ($3.d);} ;
km:	LP KM double RP {parent->model.server.kickable_margin = ($3.d);} ;
pt_km:	LP KM double RP {currentType->kickable_margin = ($3.d);} ;
lf:	LP LF string RP {parent->model.server.landmark_file = *($3.s);} ;
ldf:	LP LDF string RP {parent->model.server.log_date_format = *($3.s);} ;
lt:	LP LT int RP {parent->model.server.log_times = $3.i; } ;
mbtp:	LP MBTP double RP {parent->model.server.max_back_tackle_power = ($3.d);} ;
maxda:	LP MAXDA double RP {parent->model.server.max_dash_angle = ($3.d);} ;
mdp:	LP MDP double RP {parent->model.server.max_dash_power = ($3.d);} ;
mgk:	LP MGK int RP {parent->model.server.max_goal_kicks = $3.i; } ;
mtp:	LP MTP double RP {parent->model.server.max_tackle_power = ($3.d);} ;
maxm:	LP MAXM double RP {parent->model.server.maxmoment = ($3.d);} ;
maxna:	LP MAXNA double RP {parent->model.server.maxneckang = ($3.d);} ;
maxnm:	LP MAXNM double RP {parent->model.server.maxneckmoment = ($3.d);} ;
maxp:	LP MAXP double RP {parent->model.server.maxpower = ($3.d);} ;
minda:	LP MINDA double RP {parent->model.server.min_dash_angle = ($3.d);} ;
mindp:	LP MINDP double RP {parent->model.server.min_dash_power = ($3.d);} ;
minm:	LP MINM double RP {parent->model.server.minmoment = ($3.d);} ;
minna:	LP MINNA double RP {parent->model.server.minneckang = ($3.d);} ;
minnm:	LP MINNM double RP {parent->model.server.minneckmoment = ($3.d);} ;
minp:	LP MINP double RP {parent->model.server.minpower = ($3.d);} ;
neh:	LP NEH int RP {parent->model.server.nr_extra_halfs = $3.i; } ;
nnh:	LP NNH int RP {parent->model.server.nr_normal_halfs = $3.i; } ;
oaas:	LP OAAS double RP {parent->model.server.offside_active_area_size = ($3.d);} ;
okm:	LP OKM double RP {parent->model.server.offside_kick_margin = ($3.d);} ;
op:	LP OP int RP {parent->model.server.olcoach_port = $3.i; } ;
och:	LP OCH double RP {parent->model.server.old_coach_hear = static_cast<bool>($3.d);} ;
pamk:	LP PAMK double RP {parent->model.server.pen_allow_mult_kicks = static_cast<bool>($3.d);} ;
pbsw:	LP PBSW double RP {parent->model.server.pen_before_setup_wait = static_cast<bool>($3.d);} ;
pcmp:	LP PCMP double RP {parent->model.server.pen_coach_moves_players = static_cast<bool>($3.d);} ;
pdx:	LP PDX double RP {parent->model.server.pen_dist_x = ($3.d);} ;
pmet:	LP PMET int RP {parent->model.server.pen_max_extra_kicks = $3.i; } ;
pmgdx:	LP PMGDX int RP {parent->model.server.pen_max_goalie_dist_x = $3.i; } ;
pnk:	LP PNK int RP {parent->model.server.pen_nr_kicks = $3.i; } ;
prw:	LP PRW double RP {parent->model.server.pen_random_winner = static_cast<bool>($3.d);} ;
prwa:	LP PRWA int RP {parent->model.server.pen_ready_wait = $3.i; } ;
psw:	LP PSW int RP {parent->model.server.pen_setup_wait = $3.i; } ;
ptw:	LP PTW int RP {parent->model.server.pen_taken_wait = $3.i; } ;
pso:	LP PSO double RP {parent->model.server.penalty_shoot_outs = static_cast<bool>($3.d);} ;
pam:	LP PAM double RP {parent->model.server.player_accel_max = ($3.d);} ;
pd:	LP PD double RP {parent->model.server.player_decay = ($3.d);} ;
pt_pd:	LP PD double RP {currentType->player_decay= ($3.d);} ;
pr:	LP PR double RP {parent->model.server.player_rand = ($3.d);} ;
ps:	LP PS double RP {parent->model.server.player_size = ($3.d);} ;
pt_ps:	LP PS double RP {currentType->player_size = ($3.d);} ;
psm:	LP PSM double RP {parent->model.server.player_speed_max = ($3.d);} ;
pt_psm:	LP PSM double RP {currentType->player_speed_max = ($3.d);} ;
psmm:	LP PSMM double RP {parent->model.server.player_speed_max_min = ($3.d);} ;
pw:	LP PW double RP {parent->model.server.player_weight = ($3.d);} ;
ptb:	LP PTB int RP {parent->model.server.point_to_ban = $3.i; } ;
ptd:	LP PTD int RP {parent->model.server.point_to_duration = $3.i; } ;
p:	LP P int RP {parent->model.server.port = $3.i; } ;
pfl:	LP PFL double RP {parent->model.server.prand_factor_l = ($3.d);} ;
pfr:	LP PFR double RP {parent->model.server.prand_factor_r = ($3.d);} ;
prof:	LP PROF double RP {parent->model.server.profile = static_cast<bool>($3.d);} ;
pgk:	LP PGK double RP {parent->model.server.proper_goal_kicks = static_cast<bool>($3.d);} ;
qs:	LP QS double RP {parent->model.server.quantize_step = ($3.d);} ;
qsl:	LP QSL double RP {parent->model.server.quantize_step_l = ($3.d);} ;
rm:	LP RM double RP {parent->model.server.record_messages = static_cast<bool>($3.d);} ;
rd:	LP RD double RP {parent->model.server.recover_dec = ($3.d);} ;
rdt:	LP RDT double RP {parent->model.server.recover_dec_thr = ($3.d);} ;
ri:	LP RI double RP {parent->model.server.recover_init = ($3.d);} ;
rmin:	LP RMIN double RP {parent->model.server.recover_min = ($3.d);} ;
rs:	LP RS int RP {parent->model.server.recv_step = $3.i; } ;
rcp:	LP RCP double RP {parent->model.server.red_card_probability = ($3.d);} ;
sccm:	LP SCCM int RP {parent->model.server.say_coach_cnt_max = $3.i; } ;
scms:	LP SCMS int RP {parent->model.server.say_coach_msg_size = $3.i; } ;
sms:	LP SMS int RP {parent->model.server.say_msg_size = $3.i; } ;
sm:	LP SM double RP {parent->model.server.send_comms = static_cast<bool>($3.d);} ;
ss:	LP SS int RP {parent->model.server.send_step = $3.i; } ;
svs:	LP SVS int RP {parent->model.server.send_vi_step = $3.i; } ;
sbs:	LP SBS int RP {parent->model.server.sense_body_step = $3.i; } ;
sdr:	LP SDR double RP {parent->model.server.side_dash_rate = ($3.d);} ;
sims:	LP SIMS int RP {parent->model.server.simulator_step = $3.i; } ;
sdf:	LP SDF int RP {parent->model.server.slow_down_factor = $3.i; } ;
sotflt:	LP SOTFLT double RP {parent->model.server.slowness_on_top_for_left_team = ($3.d);} ;
sotfrt:	LP SOTFRT double RP {parent->model.server.slowness_on_top_for_right_team = ($3.d);} ;
sc:	LP SC double RP {parent->model.server.stamina_capacity = ($3.d);} ;
sim:	LP SIM double RP {parent->model.server.stamina_inc_max = ($3.d);} ;
pt_sim:	LP SIM double RP {currentType->stamina_inc_max = ($3.d);} ;
smax:	LP SMAX double RP {parent->model.server.stamina_max = ($3.d);};
sgl:	LP SGL int RP {parent->model.server.start_goal_l = $3.i; } ;
sgr:	LP SGR int RP {parent->model.server.start_goal_r = $3.i; } ;
sbv:	LP SBV double RP {parent->model.server.stopped_ball_vel = ($3.d);} ;
smics:	LP SMICS double RP {parent->model.server.synch_micro_sleep = static_cast<unsigned int>($3.d);} ;
smod:	LP SMOD double RP {parent->model.server.synch_mode = static_cast<bool>($3.d);} ;
so:	LP SO double RP {parent->model.server.synch_offset = $3.i; } ;
sso:	LP SSO double RP {parent->model.server.synch_see_offset = $3.i; } ;
tbd:	LP TBD double RP {parent->model.server.tackle_back_dist = ($3.d);} ;
tc:	LP TC double RP {parent->model.server.tackle_cycles = static_cast<unsigned int>($3.d);} ;
td:	LP TD double RP {parent->model.server.tackle_dist = ($3.d);} ;
te:	LP TE double RP {parent->model.server.tackle_exponent = ($3.d);} ;
tpr:	LP TPR double RP {parent->model.server.tackle_power_rate = ($3.d);} ;
trf:	LP TRF double RP {parent->model.server.tackle_rand_factor = ($3.d);} ;
tw:	LP TW double RP {parent->model.server.tackle_width = ($3.d);} ;
tan:	LP TAN double RP {parent->model.server.team_actuator_noise = static_cast<bool>($3.d);} ;
tls:	LP TLS string RP {parent->model.server.team_l_start = *($3.s);} ;
trs:	LP TRS string RP {parent->model.server.team_r_start = *($3.s);} ;
tlc:	LP TLC int RP {parent->model.server.text_log_compression = $3.i; } ;
tld:	LP TLD int RP {parent->model.server.text_log_dated = $3.i; } ;
tldir:	LP TLDIR string RP {parent->model.server.text_log_dir = *($3.s);} ;
tlf:	LP TLF int RP {parent->model.server.text_log_fixed = $3.i; } ;
tlfn:	LP TLFN string RP {parent->model.server.text_log_fixed_name = *($3.s);} ;
tl:	LP TL double RP {parent->model.server.text_logging = static_cast<bool>($3.d);} ;
uo:	LP UO double RP {parent->model.server.use_offside = static_cast<bool>($3.d);} ;
v:	LP V bool RP {parent->model.server.verbose = $3.b;} ;
va:	LP VA double RP {parent->model.server.visible_angle = ($3.d);} ;
vd:	LP VD double RP {parent->model.server.visible_distance = ($3.d);} ;
wa:	LP WA double RP {parent->model.server.wind_ang = ($3.d);} ;
wd:	LP WD double RP {parent->model.server.wind_dir = ($3.d);} ;
wf:	LP WF double RP {parent->model.server.wind_force = ($3.d);} ;
wn:	LP WN double RP {parent->model.server.wind_none = static_cast<bool>($3.d);} ;
wr:	LP WR double RP {parent->model.server.wind_rand = ($3.d);} ;
wra:	LP WRA double RP {parent->model.server.wind_random = ($3.d);} ;

player_param: LP PP amdt calsmax calsmin dprdmax dprdmin emaxdf emindf esdmax esdmin fdpdf imdf
kprdmax kprdmin kprdf kmdmax kmdmin ndprdmax ndprdmin nsimaxdf pddmax pddmin
psdf psmaxdmax psmaxdmin pt ptm rans simaxdf submax RP {cout << "seen player_param" << endl; this->ACCEPT();};

player_type: LP PTY id pt_psm pt_sim pt_pd pt_im pt_dpr pt_ps pt_km pt_kr pt_es
pt_emx pt_emi pt_kpr pt_fdp pt_cals RP {cout << "seen player_type " << currentType->id << endl; this->ACCEPT();};

amdt:		LP AMDT double RP {parent->model.player.allow_mult_default_type = ($3.d);};
calsmax:	LP CALSMAX double RP {parent->model.player.catchable_area_l_stretch_max = ($3.d);};
pt_cals:	LP CALS double RP {currentType->catchable_area_l_stretch = ($3.d);};
calsmin:	LP CALSMIN double RP {parent->model.player.catchable_area_l_stretch_min = ($3.d);};
dprdmax:	LP DPRDMAX double RP {parent->model.player.dash_power_rate_delta_max = ($3.d);};
dprdmin:	LP DPRDMIN double RP {parent->model.player.dash_power_rate_delta_min = ($3.d);};
emaxdf:		LP EMAXDF double RP {parent->model.player.effort_max_delta_factor = ($3.d);};
emindf:		LP EMINDF double RP {parent->model.player.effort_min_delta_factor = ($3.d);};
esdmax:		LP ESDMAX double RP {parent->model.player.extra_stamina_delta_max = ($3.d);};
esdmin:		LP ESDMIN double RP {parent->model.player.extra_stamina_delta_min = ($3.d);};
fdpdf:		LP FDPDF double RP {parent->model.player.foul_detect_probability_delta_factor = ($3.d);};
imdf:		LP IMDF double RP {parent->model.player.inertia_moment_delta_factor = ($3.d);};
kprdmax:	LP KPRDMAX double RP {parent->model.player.kick_power_rate_delta_max = ($3.d);};
kprdmin:	LP KPRDMIN double RP {parent->model.player.kick_power_rate_delta_min = ($3.d);};
kprdf:		LP KPRDF double RP {parent->model.player.kick_rand_delta_factor = ($3.d);};
kmdmax:		LP KMDMAX double RP {parent->model.player.kickable_margin_delta_max = ($3.d);};
kmdmin:		LP KMDMIN double RP {parent->model.player.kickable_margin_delta_min = ($3.d);};
ndprdmax:	LP NDPRDMAX double RP {parent->model.player.new_dash_power_rate_delta_max = ($3.d);};
ndprdmin:	LP NDPRDMIN double RP {parent->model.player.new_dash_power_rate_delta_min = ($3.d);};
nsimaxdf:	LP NSIMAXDF double RP {parent->model.player.new_stamina_inc_max_delta_factor = ($3.d);};
pddmax:		LP PDDMAX double RP {parent->model.player.player_decay_delta_max = ($3.d);};
pddmin:		LP PDDMIN double RP {parent->model.player.player_decay_delta_min = ($3.d);};
psdf:		LP PSDF double RP {parent->model.player.player_size_delta_factor = ($3.d);};
psmaxdmax:	LP PSMAXDMAX double RP {parent->model.player.player_speed_max_delta_max = ($3.d);};
psmaxdmin:	LP PSMAXDMIN double RP {parent->model.player.player_speed_max_delta_min = ($3.d);};
pt:		LP PT int RP {parent->model.player.player_types = $3.i; };
ptm:		LP PTM int RP {parent->model.player.pt_max = $3.i; };
rans:		LP RANS int RP {parent->model.player.random_seed = $3.i; };
simaxdf:	LP SIMAXDF double RP {parent->model.player.stamina_inc_max_delta_factor = ($3.d);};
submax: 	LP SUBMAX int RP {parent->model.player.subs_max = $3.i; };

id:		LP ID int RP {
    t_player_type x;
    parent->model.player_types.push_back(x);
    currentType = parent->model.player_types.rbegin();
    currentType->id = $3.i;
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
                    parent->model.body.stamina.stamina = $3.d;
                    parent->model.body.stamina.effort = $4.d;
                    parent->model.body.stamina.capacity = $5.d;
                };
sp:		LP SP double double RP {parent->model.body.speed.x = $3.d; parent->model.body.speed.y = $4.d;};
ha:		LP HA int RP {parent->model.body.head_angle = $3.i;};
kick:		LP KICK int RP {parent->model.body.kick = $3.i;};
dash:		LP DASH int RP {parent->model.body.dash = $3.i;};
turn:		LP TURN int RP {parent->model.body.turn = $3.i;};
say:		LP SAY int RP {parent->model.body.say = $3.i;};
tneck:		LP TNECK int RP {parent->model.body.turn_neck = $3.i;};
catch:		LP CATCH int RP {parent->model.body.catch_ = $3.i;};
move:		LP MOVE int RP {parent->model.body.move = $3.i;};
chview:		LP CHVIEW int RP {parent->model.body.change_view = $3.i;};

arm:		LP ARM movable expires target count RP;
movable:	LP MOVABLE int RP {parent->model.body.arm.movable = $3.i;};
expires:	LP EXP int RP {parent->model.body.arm.expires = $3.i;};
target:		LP TAR double double RP {parent->model.body.arm.target = Point($3.d,$4.d);};
count:		LP COUNT int RP {parent->model.body.arm.count = $3.i;};

focus:		LP FOCUS f_target f_count RP;
f_target:	LP TAR target_type RP {parent->model.body.focus.type = static_cast<t_focus::focus_type>($3.i);};
f_count:	LP COUNT int RP {};
target_type:	_L {$$.i = t_focus::l;} |
		_R {$$.i = t_focus::r;} |
		NONE {$$.i = t_focus::none;};

tackle:		LP TACKLE t_expires t_count RP;
t_expires:	LP EXP int RP {parent->model.body.tackle.expires = $3.i;};
t_count:	LP COUNT int RP {parent->model.body.tackle.count = $3.i;};

collision:	LP COLL col_type RP {parent->model.body.collition.type = static_cast<t_collition::collition_type>($3.i);};
col_type:	NONE {$$.i = t_collition::none;} |
		BALL {$$.i = t_collition::ball;} |
		PLAYER {$$.i = t_collition::player;} |
		POST {$$.i = t_collition::post;};

foul:		LP FOUL charged card RP;
charged:	LP CHARGED int RP {parent->model.body.foul.charged = $3.i;};
card:		LP CARD card_type RP {parent->model.body.foul.card = static_cast<t_foul::card_type>($3.i);};
card_type:	NONE {$$.i = t_foul::none;} |
		YELLOW {$$.i = t_foul::yellow;};

see:		LP SEE int objects RP {cout << "seen see" << endl;};
objects:	object objects |
		object ;
object:		o_ball |
		o_player |
		o_goal |
		o_flag ;

o_ball:		LP LP _B RP double double RP {} |
		LP LP _B RP double double double double RP {};
o_player:	LP LP _P string int RP double double double double double double RP {} |
		LP LP _P string int GOALIE RP double double double double double double RP {} |
		LP LP _P string RP double double RP {} |
		LP LP _P RP double double RP {};
o_goal:		LP LP _G side RP double double RP {} |
		LP LP _G side RP double double double double RP {};
o_flag:		LP LP flag_name RP double double RP {}|
		LP LP flag_name RP double double double double RP {};
flag_name:	_F _C |
		_F side tb {} |
		_F _C tb {} |
		_F _P side tcb |
		_F _G side tb |
		_F lrtb _0 |
		_F tb side int |
		_F side tb int |
		_L lrtb |
		_BB |
		_FF |
		_GG |
		_PP
		;
tb:		_T | _B;
side:		_L {$$.i=0;} | _R {$$.i=1;};
tcb:		_T | _C | _B ;
lrtb:		_L | _R | _T | _B;
