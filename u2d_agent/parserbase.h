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
    // see
    void ss_startRead();
    void ss_readParameter();
signals:

public slots:

};

#endif // PARSERBASE_H
