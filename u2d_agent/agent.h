#ifndef AGENT_H
#define AGENT_H

#include <QCoreApplication>
#include "connection.h"
#include "parserbase.h"
#include "sensor.h"

class Connection;
class ParserBase;

class Agent : public QCoreApplication
{
    Q_OBJECT
public:
    explicit Agent(int argc, char *argv[]);
    QString teamName;
    Connection connection;
    ParserBase parser;
    Sensor sensors;
    bool goalie;
    QString configurationFile;
signals:

public slots:

};

#endif // AGENT_H
