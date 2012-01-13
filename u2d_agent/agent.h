#ifndef AGENT_H
#define AGENT_H

#include <QCoreApplication>
#include "connection.h"
#include "parserbase.h"
#include "see.h"
#include "sense_body.h"

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
    bool goalie;
    sense_body body;
    see visual;
    QString configurationFile;
signals:

public slots:
    void play();
    void init();
};

#endif // AGENT_H
