%scanner                ./Scanner.h
%scanner-token-function d_scanner.lex()

%union{
double		d;
int		i;
std::string*	s;
}

%token <d> 	DOUBLE
%token <s> 	STRING

%token INIT
%token SERVER
%token LP
%token RP

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

%token SIDE PLM

%token PP AMDT CALSMAX CALSMIN DPRDMAX DPRDMIN EMAXDF EMINDF ESDMAX ESDMIN FDPDF IMDF
KPRDMAX KPRDMIN KPRDF KMDMAX KMDMIN NDPRDMAX NDPRDMIN NSIMAXDF PDDMAX PDDMIN
PSDF PSMAXDMAX PSMAXDMIN PT PTM RANS SIMAXDF SUBMAX


%token PM_BKO PM_PO PM_TO PM_KOL PM_KOR PM_KIL PM_KIR PM_FKL PM_FKR
PM_CKL PM_CKR PM_GKL PM_GKR PM_GOALL PM_GOALR PM_DB PM_OL PM_OR

%%

start: init | server_param | player_param;

double:	DOUBLE {$$.d = atof(d_scanner->matched().c_str());} ;
string:	STRING {$$.s = new std::string(d_scanner->matched().c_str());} ;

init:   LP INIT SIDE double play_mode RP {parent->model.play_mode = (Model::play_mode_type)$5.i; cout << "init Response received " << parent->model.play_mode << endl;};
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
tlf tlfn tl uo v va vd wa wd wf wn wr wra RP {cout << "end of server_param version 15" << endl;};
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

acd:	LP ACD double RP {parent->model.server.audio_cut_dist = $3.d;} ;
am:	LP AM double RP {parent->model.server.auto_mode = ($3.d==0?false:true);}; // not in 8
bdr:	LP BDR double RP {parent->model.server.back_dash_rate = $3.d;} ;
bp:	LP BP double RP {parent->model.server.back_passes = static_cast<bool>($3.d);} ;
bam:	LP BAM double RP {parent->model.server.ball_accel_max = $3.d;} ;
bd:	LP BD double RP {parent->model.server.ball_decay = $3.d;} ;
br:	LP BR double RP {parent->model.server.ball_rand = $3.d;} ;
bs:	LP BS double RP {parent->model.server.ball_size = $3.d;} ;
bsm:	LP BSM double RP {parent->model.server.ball_speed_max = $3.d;} ;
bsa:	LP BSA double RP {parent->model.server.ball_stuck_area = $3.d;} ;
bw:	LP BW double RP {parent->model.server.ball_weight = $3.d;} ;
cbc:	LP CBC double RP {parent->model.server.catch_ban_cycle = static_cast<int>($3.d);} ;
cp:	LP CP double RP {parent->model.server.catch_probability = $3.d;} ;
cal:	LP CAL double RP {parent->model.server.catchable_area_l = $3.d;} ;
caw:	LP CAW double RP {parent->model.server.catchable_area_w = $3.d;} ;
cm:	LP CM double RP {parent->model.server.ckick_margin = $3.d;} ;
cadw:	LP CADW double RP {parent->model.server.clang_advice_win = static_cast<int>($3.d);} ;
cdefw:	LP CDEFW double RP {parent->model.server.clang_define_win = static_cast<int>($3.d);} ;
cdelw:	LP CDELW double RP {parent->model.server.clang_del_win = static_cast<int>($3.d);} ;
ciw:	LP CIW double RP {parent->model.server.clang_info_win = static_cast<int>($3.d);} ;
cmd:	LP CMD double RP {parent->model.server.clang_mess_delay = static_cast<int>($3.d);} ;
cmpc:	LP CMPC double RP {parent->model.server.clang_mess_per_cycle = static_cast<int>($3.d);} ;
cmw:	LP CMW double RP {parent->model.server.clang_meta_win = static_cast<int>($3.d);} ;
crw:	LP CRW double RP {parent->model.server.clang_rule_win = static_cast<int>($3.d);} ;
cws:	LP CWS double RP {parent->model.server.clang_win_size = static_cast<int>($3.d);} ;
co:	LP CO double RP {parent->model.server.coach = ($3.d==0?false:true);} ;
cop:	LP COP double RP {parent->model.server.coach_port = static_cast<int>($3.d);} ;
cwr:	LP CWR double RP {parent->model.server.coach_w_referee = ($3.d==0?false:true);} ;
cw:	LP CW double RP {parent->model.server.connect_wait = static_cast<int>($3.d);}; // not in version 8
cr:	LP CR double RP {parent->model.server.control_radius = $3.d;} ;
das:	LP DAS double RP {parent->model.server.dash_angle_step = $3.d;} ;
dpr:	LP DPR double RP {parent->model.server.dash_power_rate = $3.d;} ;
dbt:	LP DBT double RP {parent->model.server.drop_ball_time = static_cast<int>($3.d);} ;
ed:	LP ED double RP {parent->model.server.effort_dec = ($3.d);} ;
edt:	LP EDT double RP {parent->model.server.effort_dec_thr = ($3.d);} ;
ein:	LP EIN double RP {parent->model.server.effort_inc = ($3.d);} ;
eit:	LP EIT double RP {parent->model.server.effort_inc_thr = ($3.d);} ;
ei:	LP EI double RP {parent->model.server.effort_init = ($3.d);} ;
em:	LP EM double RP {parent->model.server.effort_min = ($3.d);} ;
eht:	LP EHT double RP {parent->model.server.extra_half_time = static_cast<int>($3.d);} ;
es:	LP ES double RP {parent->model.server.extra_stamina = ($3.d);} ;
fko:	LP FKO double RP {parent->model.server.forbid_kick_off_offside = static_cast<bool>($3.d);} ;
fc:	LP FC double RP {parent->model.server.foul_cycles = static_cast<int>($3.d);} ;
fdp:	LP FDP double RP {parent->model.server.foul_detect_probability = $3.d;} ;
fe:	LP FE double RP {parent->model.server.foul_exponent = $3.d;} ;
fkf:	LP FKF double RP {parent->model.server.free_kick_faults = static_cast<bool>($3.d);} ;
fsp:	LP FSP double RP {parent->model.server.freeform_send_period = static_cast<unsigned int>($3.d);} ;
fwp:	LP FWP double RP {parent->model.server.freeform_wait_period = static_cast<unsigned int>($3.d);} ;
fl:	LP FL double RP {parent->model.server.fullstate_l = static_cast<int>($3.d);} ;
fr:	LP FR double RP {parent->model.server.fullstate_r = static_cast<int>($3.d);} ;
glc:	LP GLC double RP {parent->model.server.game_log_compression = static_cast<int>($3.d);} ;
gld:	LP GLD double RP {parent->model.server.game_log_dated = static_cast<int>($3.d);} ;
gldir:	LP GLDIR string RP {parent->model.server.game_log_dir = *($3.s);} ;
glf:	LP GLF double RP {parent->model.server.game_log_fixed= static_cast<bool>($3.d);} ;
glfn:	LP GLFN string RP {parent->model.server.game_log_fixed_name = *($3.s);} ;
glv:	LP GLV double RP {parent->model.server.game_log_version = static_cast<int>($3.d);} ;
gl:	LP GL double RP {parent->model.server.game_logging = static_cast<bool>($3.d);} ;
gow:	LP GOW double RP {parent->model.server.game_over_wait = static_cast<int>($3.d);}; // not in version 8
gw:	LP GW double RP {parent->model.server.goal_width = ($3.d);} ;
gmm:	LP GMM double RP {parent->model.server.goalie_max_moves = static_cast<int>($3.d);} ;
gg:	LP GG double RP {parent->model.server.golden_goal = static_cast<bool>($3.d);} ;
ht:	LP HT double RP {parent->model.server.half_time = static_cast<int>($3.d);} ;
hd:	LP HD double RP {parent->model.server.hear_decay = static_cast<unsigned int>($3.d);} ;
hi:	LP HI double RP {parent->model.server.hear_inc = static_cast<unsigned int>($3.d);} ;
hm:	LP HM double RP {parent->model.server.hear_max = static_cast<unsigned int>($3.d);} ;
im:	LP IM double RP {parent->model.server.inertia_moment = ($3.d);} ;
k:	LP K double RP {parent->model.server.keepaway = static_cast<bool>($3.d);} ;
kl:	LP KL double RP {parent->model.server.keepaway_length = ($3.d);} ;
kld:	LP KLD double RP {parent->model.server.keepaway_log_dated = static_cast<bool>($3.d);} ;
kldir:	LP KLDIR string RP {parent->model.server.keepaway_log_dir = *($3.s);} ;
lkf:	LP LKF double RP {parent->model.server.keepaway_log_fixed = static_cast<bool>($3.d);} ;
klfn:	LP KLFN string RP {parent->model.server.keepaway_log_fixed_name = *($3.s);} ;
klg:	LP KLG double RP {parent->model.server.keepaway_logging = static_cast<bool>($3.d);} ;
ks:	LP KS double RP {parent->model.server.keepaway_start = static_cast<int>($3.d);} ;
kw:	LP KW double RP {parent->model.server.keepaway_width = ($3.d);} ;
kow:	LP KOW double RP {parent->model.server.kick_off_wait = static_cast<int>($3.d);} ;
kpr:	LP KPR double RP {parent->model.server.kick_power_rate = ($3.d);} ;
kr:	LP KR double RP {parent->model.server.kick_rand = ($3.d);} ;
krfl:	LP KRFL double RP {parent->model.server.kick_rand_factor_l = ($3.d);} ;
krfr:	LP KRFR double RP {parent->model.server.kick_rand_factor_r = ($3.d);} ;
km:	LP KM double RP {parent->model.server.kickable_margin = ($3.d);} ;
lf:	LP LF string RP {parent->model.server.landmark_file = *($3.s);} ;
ldf:	LP LDF string RP {parent->model.server.log_date_format = *($3.s);} ;
lt:	LP LT double RP {parent->model.server.log_times = static_cast<int>($3.d);} ;
mbtp:	LP MBTP double RP {parent->model.server.max_back_tackle_power = ($3.d);} ;
maxda:	LP MAXDA double RP {parent->model.server.max_dash_angle = ($3.d);} ;
mdp:	LP MDP double RP {parent->model.server.max_dash_power = ($3.d);} ;
mgk:	LP MGK double RP {parent->model.server.max_goal_kicks = static_cast<int>($3.d);} ;
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
neh:	LP NEH double RP {parent->model.server.nr_extra_halfs = static_cast<int>($3.d);} ;
nnh:	LP NNH double RP {parent->model.server.nr_normal_halfs = static_cast<int>($3.d);} ;
oaas:	LP OAAS double RP {parent->model.server.offside_active_area_size = ($3.d);} ;
okm:	LP OKM double RP {parent->model.server.offside_kick_margin = ($3.d);} ;
op:	LP OP double RP {parent->model.server.olcoach_port = static_cast<int>($3.d);} ;
och:	LP OCH double RP {parent->model.server.old_coach_hear = static_cast<bool>($3.d);} ;
pamk:	LP PAMK double RP {parent->model.server.pen_allow_mult_kicks = static_cast<bool>($3.d);} ;
pbsw:	LP PBSW double RP {parent->model.server.pen_before_setup_wait = static_cast<bool>($3.d);} ;
pcmp:	LP PCMP double RP {parent->model.server.pen_coach_moves_players = static_cast<bool>($3.d);} ;
pdx:	LP PDX double RP {parent->model.server.pen_dist_x = ($3.d);} ;
pmet:	LP PMET double RP {parent->model.server.pen_max_extra_kicks = static_cast<int>($3.d);} ;
pmgdx:	LP PMGDX double RP {parent->model.server.pen_max_goalie_dist_x = static_cast<int>($3.d);} ;
pnk:	LP PNK double RP {parent->model.server.pen_nr_kicks = static_cast<int>($3.d);} ;
prw:	LP PRW double RP {parent->model.server.pen_random_winner = static_cast<bool>($3.d);} ;
prwa:	LP PRWA double RP {parent->model.server.pen_ready_wait = static_cast<int>($3.d);} ;
psw:	LP PSW double RP {parent->model.server.pen_setup_wait = static_cast<int>($3.d);} ;
ptw:	LP PTW double RP {parent->model.server.pen_taken_wait = static_cast<int>($3.d);} ;
pso:	LP PSO double RP {parent->model.server.penalty_shoot_outs = static_cast<bool>($3.d);} ;
pam:	LP PAM double RP {parent->model.server.player_accel_max = ($3.d);} ;
pd:	LP PD double RP {parent->model.server.player_decay = ($3.d);} ;
pr:	LP PR double RP {parent->model.server.player_rand = ($3.d);} ;
ps:	LP PS double RP {parent->model.server.player_size = ($3.d);} ;
psm:	LP PSM double RP {parent->model.server.player_speed_max = ($3.d);} ;
psmm:	LP PSMM double RP {parent->model.server.player_speed_max_min = ($3.d);} ;
pw:	LP PW double RP {parent->model.server.player_weight = ($3.d);} ;
ptb:	LP PTB double RP {parent->model.server.point_to_ban = static_cast<int>($3.d);} ;
ptd:	LP PTD double RP {parent->model.server.point_to_duration = static_cast<int>($3.d);} ;
p:	LP P double RP {parent->model.server.port = static_cast<int>($3.d);} ;
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
rs:	LP RS double RP {parent->model.server.recv_step = static_cast<int>($3.d);} ;
rcp:	LP RCP double RP {parent->model.server.red_card_probability = ($3.d);} ;
sccm:	LP SCCM double RP {parent->model.server.say_coach_cnt_max = static_cast<int>($3.d);} ;
scms:	LP SCMS double RP {parent->model.server.say_coach_msg_size = static_cast<int>($3.d);} ;
sms:	LP SMS double RP {parent->model.server.say_msg_size = static_cast<int>($3.d);} ;
sm:	LP SM double RP {parent->model.server.send_comms = static_cast<bool>($3.d);} ;
ss:	LP SS double RP {parent->model.server.send_step = static_cast<int>($3.d);} ;
svs:	LP SVS double RP {parent->model.server.send_vi_step = static_cast<int>($3.d);} ;
sbs:	LP SBS double RP {parent->model.server.sense_body_step = static_cast<int>($3.d);} ;
sdr:	LP SDR double RP {parent->model.server.side_dash_rate = ($3.d);} ;
sims:	LP SIMS double RP {parent->model.server.simulator_step = static_cast<int>($3.d);} ;
sdf:	LP SDF double RP {parent->model.server.slow_down_factor = static_cast<int>($3.d);} ;
sotflt:	LP SOTFLT double RP {parent->model.server.slowness_on_top_for_left_team = ($3.d);} ;
sotfrt:	LP SOTFRT double RP {parent->model.server.slowness_on_top_for_right_team = ($3.d);} ;
sc:	LP SC double RP {parent->model.server.stamina_capacity = ($3.d);} ;
sim:	LP SIM double RP {parent->model.server.stamina_inc_max = ($3.d);} ;
smax:	LP SMAX double RP {parent->model.server.stamina_max = ($3.d);} ;
sgl:	LP SGL double RP {parent->model.server.start_goal_l = static_cast<int>($3.d);} ;
sgr:	LP SGR double RP {parent->model.server.start_goal_r = static_cast<int>($3.d);} ;
sbv:	LP SBV double RP {parent->model.server.stopped_ball_vel = ($3.d);} ;
smics:	LP SMICS double RP {parent->model.server.synch_micro_sleep = static_cast<unsigned int>($3.d);} ;
smod:	LP SMOD double RP {parent->model.server.synch_mode = static_cast<bool>($3.d);} ;
so:	LP SO double RP {parent->model.server.synch_offset = static_cast<int>($3.d);} ;
sso:	LP SSO double RP {parent->model.server.synch_see_offset = static_cast<int>($3.d);} ;
tbd:	LP TBD double RP {parent->model.server.tackle_back_dist = ($3.d);} ;
tc:	LP TC double RP {parent->model.server.tackle_cycles = static_cast<unsigned int>($3.d);} ;
td:	LP TD double RP {parent->model.server.tackle_dist = ($3.d);} ;
te:	LP TE double RP {parent->model.server.tackle_exponent = ($3.d);} ;
tpr:	LP TPR double RP {parent->model.server.tackle_power_rate = ($3.d);} ;
trf:	LP TRF double RP {parent->model.server.tackle_rand_factor = ($3.d);} ;
tw:	LP TW double RP {parent->model.server.tackle_width = ($3.d);} ;
tan:	LP TAN double RP {parent->model.server.team_actuator_noise = static_cast<bool>($3.d);} ;
tls:	LP TLS string RP {parent->model.server.team_l_start = *($3.s);} ;
trs:	LP TRS string RP {parent->model.server.team_r_start = ($3.d);} ;
tlc:	LP TLC double RP {parent->model.server.text_log_compression = static_cast<int>($3.d);} ;
tld:	LP TLD double RP {parent->model.server.text_log_dated = static_cast<int>($3.d);} ;
tldir:	LP TLDIR string RP {parent->model.server.text_log_dir = *($3.s);} ;
tlf:	LP TLF double RP {parent->model.server.text_log_fixed = static_cast<int>($3.d);} ;
tlfn:	LP TLFN string RP {parent->model.server.text_log_fixed_name = *($3.s);} ;
tl:	LP TL double RP {parent->model.server.text_logging = static_cast<bool>($3.d);} ;
uo:	LP UO double RP {parent->model.server.use_offside = static_cast<bool>($3.d);} ;
v:	LP V double RP {parent->model.server.verbose = static_cast<bool>($3.d);} ;
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
psdf psmaxdmax psmaxdmin pt ptm rans simaxdf submax RP {cout << "player parameters received" << endl;};

amdt:		LP AMDT double RP {parent->model.player.allow_mult_default_type = static_cast<double>($3.d);};
calsmax:	LP CALSMAX double RP {parent->model.player.catchable_area_l_stretch_max = ($3.d);};
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
pt:		LP PT double RP {parent->model.player.player_types = static_cast<int>($3.d);};
ptm:		LP PTM double RP {parent->model.player.pt_max = static_cast<int>($3.d);};
rans:		LP RANS double RP {parent->model.player.random_seed = static_cast<int>($3.d);};
simaxdf:	LP SIMAXDF double RP {parent->model.player.stamina_inc_max_delta_factor = ($3.d);};
submax: 	LP SUBMAX double RP {parent->model.player.subs_max = static_cast<int>($3.d);};
