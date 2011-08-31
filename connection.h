#ifndef CONNECTION_H
#define CONNECTION_H

#include <QUdpSocket>

class Agent;

class Connection : private QUdpSocket
{
    Q_OBJECT
public:
    explicit Connection(Agent *parent = 0);
    Connection(const Connection&);
    QHostAddress address;
    quint16 portNumber;
    inline Agent* agent(){return (Agent*)parent();}
    void initialize();
signals:

public slots:
    void processData();

};

#endif // CONNECTION_H
