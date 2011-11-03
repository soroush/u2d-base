#ifndef AGENT_H
#define AGENT_H

#include <QCoreApplication>
#include "connection.h"
#include "server_param.h"

class Connection;

class Agent : public QCoreApplication
{
    Q_OBJECT
public:
    explicit Agent(int argc, char *argv[]);
    QString teamName;
    Connection connection;
    server_param server_param_sensor;
signals:

public slots:

};

#endif // AGENT_H
