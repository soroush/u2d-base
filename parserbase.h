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
signals:

public slots:

};

#endif // PARSERBASE_H
