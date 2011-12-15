#include "connection.h"
#include "agent.h"
#include "parserbase.h"
#include "see.h"
#include <QString>
#include <iostream>

Connection::Connection(Agent *parent) :
    QUdpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(processData()));
}

Connection::Connection(const Connection & other):
    QUdpSocket(other.parent()),
    address(QHostAddress::LocalHost),
    portNumber(6000)
{
}

void Connection:: initialize()
{
    if(!bind(0))
    {
        std::cout << "Unable to Bind to server!" <<std::endl;
        exit(1);
    }
    else
    {
        std::cout << "Binded to server" << std::endl;
    }
    std::cout << "Address:\t\t" << address.toString().toAscii().data()<<std::endl;
    std::cout << "Port:\t\t\t" << portNumber << std::endl;
    QString initializeCommand(QString("(init %1 (version 14))").arg(agent()->teamName));
    std::cout << "init datagram size:\t" << writeDatagram(initializeCommand.toAscii(),QHostAddress::LocalHost,this->portNumber)
              << std::endl;
    //=================================================
//    this->agent()->parser.input = "(see 30 ((f p r c) 10 10 10 10.1) ((p) 97.1 1.2) ((p \"team A\" 10 goalie) 100 200 1 2 3 4) ((f r t) 0.1 1.2) ((f c b) 0.1 1 1 1) ((f c t) 10 10 9 10.1))";
//    this->agent()->parser.i = 0;
//    this->agent()->parser.start();
//    for(int i=0; i<see::seeingObjects.length();++i)
//    {
//        object* seeing = see::seeingObjects.at(i);
//        std::cout << i << ":"
//              << seeing->data->distance << " "
//              << seeing->data->direction << " "
//              << ((seeing->data->parameterCount==seeing->data->P4) ? seeing->data->distChange : -1000) << " "
//              << ((seeing->data->parameterCount==seeing->data->P4) ? seeing->data->dirChange : -1000) << " " << std::endl;
//    }
    //=================================================
    waitForReadyRead();
}

void Connection::processData()
{
    char buffer[8192];
    while ( hasPendingDatagrams() )
    {
        quint16 newPortNumber;
        int n = readDatagram( buffer, pendingDatagramSize(), 0, &newPortNumber );
        if ( n > 0 )
        {
            buffer[n] = '\0';
            if ( newPortNumber != portNumber )
            {
                portNumber = newPortNumber;
            }
            this->agent()->parser.input = buffer;
            this->agent()->parser.i = 0;
            this->agent()->parser.start();
        }
        waitForReadyRead();
    }
}
