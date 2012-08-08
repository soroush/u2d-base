#include "connection.h"
#include "../agent.h"
#include <iostream>
#include <arpa/inet.h>

using namespace std;

Connection::Connection()
{
}

Connection::Connection(const char *ip, const unsigned int &portNumber, Agent* _parant)
    :parant(_parant)
{
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons(portNumber);
}

Connection::Connection(const std::string &ip, const unsigned int &portNumber, Agent *_parent)
    :parant(_parent)
{
    Connection(ip.c_str(),portNumber);
}

void Connection::initialize(const string &ip, const unsigned int &portNumber, Agent *_parent)
{
    this->parant = _parent;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip.c_str());
    address.sin_port = htons(portNumber);
}

void Connection::loop()
{
    //cout << "Initialization: " << initializeCommand << endl;
    char* buffer = new char[8192];
    sendto(sockfd,initializeCommand.c_str(),initializeCommand.length(),0, (struct sockaddr *) &address,sizeof(address));
    int n;
    int i=0;
    while(true)
    {
        n = recvfrom(sockfd, buffer, 8192, 0, NULL,NULL);
        buffer[n] = 0;
        parant->parse(buffer);
        i++;
    }
}

void Connection::setInitializationCommand(const string &command)
{
    this->initializeCommand = command;
}
