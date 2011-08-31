#include "parserbase.h"

bool ParserBase::expectInt = false;

ParserBase::ParserBase(QObject *parent) :
    QObject(parent)
{
}
