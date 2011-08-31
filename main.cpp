#include "agent.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    Agent a(argc, argv);
    return a.exec();
}
