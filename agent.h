#ifndef AGENT_H
#define AGENT_H

#include <QCoreApplication>
#include "connection.h"

class Connection;

class Agent : public QCoreApplication
{
    Q_OBJECT
public:
    explicit Agent(int argc, char *argv[]);
    QString teamName;
    Connection connection;
signals:

public slots:

};

#endif // AGENT_H
