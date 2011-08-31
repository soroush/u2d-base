#include "connection.h"
#include "agent.h"
#include <QString>

Connection::Connection(Agent *parent) :
    QUdpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(processData()));
}

Connection::Connection(const Connection & other):
    QUdpSocket(other.parent())
{
}

void Connection::initialize()
{
    if(!bind(0))
    {
        qDebug() << "Unable to Bind to server";
        exit(1);
    }
    else
    {
        qDebug() << "Binded to server";
    }
    qDebug() << address;
    qDebug() << portNumber;
    QString initializeCommand(QString("(init %1 (version 14))").arg(agent()->teamName));
    qDebug()<<writeDatagram(initializeCommand.toAscii(),QHostAddress::LocalHost,portNumber);
    waitForReadyRead();
}

void Connection::processData()
{
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
                qDebug() << "updated server port number:\t" << newPortNumber;
                qDebug() << "localPort:\t" << localPort();
                portNumber = newPortNumber;
            }
            // Testing proposed:
             qDebug() << buffer;
            /*
            * Send readed data to PARSER
            * PARSER should tokenize the input string and extract data from it
            * then it should send data to BRAIN part
             */
//            yyFlexLexer lexer;
        }
        waitForReadyRead();
    }
}
