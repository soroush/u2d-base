#ifndef PARSERBASE_H
#define PARSERBASE_H

#include <QObject>

class ParserBase : public QObject
{
    Q_OBJECT
public:
    explicit ParserBase(QObject *parent = 0);
    char* input;
    int size;
    int i;      // index
    void start();
    void readSensorName();
    // init
    void readTeamSide();
    void readFormNumber();
    void readPlayMode();
    // server_param:
    void sp_read();
    void sp_readParameterName();
    void sp_au();
    void sp_ba();
    void sp_ball_();
    void sp_c();
    void sp_catch();
    void sp_clang_();
    void sp_d();
    void sp_e();
    void sp_effort_();
    void sp_extra_();
    void sp_dash_();
    void sp_fo();
    void sp_free();
    void sp_fullstate_();
    void sp_g();
    void sp_game_();
    void sp_game_log_();
    void sp_go();
    void sp_golden_goal();
    void sp_half_time();
    void sp_hear_();
    void sp_inertia_moment();
    void sp_keepaway();
    void sp_keepaway_log_d();
    void sp_kick();
    // sense_body:
    void sb_startRead();
    void sb_readParameter(); // deprecated
    void sb_view_mode();
    void sb_stamina();
    void sb_speed();
    void sb_head_angle();
    void sb_kick();
    void sb_dash();
    void sb_turn();
    void sb_say();
    void sb_turn_neck();
    void sb_catch();
    void sb_move();
    void sb_change_view();
    void sb_arm();
    void sb_arm_movable();
    void sb_arm_expires();
    void sb_arm_target();
    void sb_arm_count();
    void sb_focus();
    void sb_focus_target();
    void sb_focus_count();
    void sb_tackle();
    void sb_tackle_expires();
    void sb_tackle_count();
    void sb_collision();
    void sb_foul();
    void sb_foul_charged();
    void sb_foul_card();
signals:

public slots:

};

#endif // PARSERBASE_H
