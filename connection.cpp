#include "connection.h"
#include "agent.h"
#include "parserbase.h"
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
    waitForReadyRead();
}

void Connection::processData()
{
//    int counter = 0;
    char buffer[8192];
    while ( hasPendingDatagrams() )
    {
        quint16 newPortNumber;
        int n = readDatagram( buffer, pendingDatagramSize(), 0,
                                     // QHostAddress*
                                     &newPortNumber );
        if ( n > 0 )
        {
            buffer[n] = '\0';
            if ( newPortNumber != portNumber )
            {
                // Testing proposed:
                std::cout << "updated server port:\t" << newPortNumber <<std::endl;
                std::cout << "localPort:\t\t" << localPort()<<std::endl;
                portNumber = newPortNumber;
            }
            // Testing proposed:
            /*
            * Send readed data to PARSER
            * PARSER should tokenize the input string and extract data from it
            * then it should send data to BRAIN part
             */
//            std::cout<<counter++<<": "<<std::endl;
//            std::cout<<buffer<<std::endl;
            this->agent()->parser.input = buffer;
            this->agent()->parser.i = 0;
            this->agent()->parser.start();
        }
        waitForReadyRead();
    }
}
