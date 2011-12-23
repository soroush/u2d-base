#ifndef PARSERBASE_H
#define PARSERBASE_H

#include <QObject>

class Agent;

class ParserBase : public QObject
{
    Q_OBJECT
public:
    explicit ParserBase(QObject *parent = 0);
    // parent:
    Agent* agent;
    char* input;
    int size;
    int i;      // index
    void start();
    void readSensorName();
    // init
    void i_startRead();
    void readPlayMode();
    // server_param:
    void sp_startRead();
    // player_type:
    void pt_startRead();
    void pt_readParameter();
    // player_param:
    void pp_startRead();
    void pp_readParameter();
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
    // see
    void ss_startRead();
    void ss_readParameter();
signals:

public slots:

};

#endif // PARSERBASE_H
