#include "see.h"

QList<object*> see::seeingObjects;
int see::time;

objectType objectType::gl   ={-52.50,+00.00};
objectType objectType::gr   ={+52.50,+00.00};
objectType objectType::fc   ={+00.00,+00.00};
objectType objectType::flt  ={-52.50,-34.00};
objectType objectType::flb  ={-52.50,+34.00};
objectType objectType::fct  ={+00.00,-34.00};
objectType objectType::fcb  ={+00.00,+34.00};
objectType objectType::frt  ={+52.50,-34.00};
objectType objectType::frb  ={+52.50,+34.00};
objectType objectType::fplt ={-36.00,-20.15};
objectType objectType::fplc ={-36.00,+00.00};
objectType objectType::fplb ={-36.00,+20.15};
objectType objectType::fprt ={+36.00,-20.15};
objectType objectType::fprc ={+36.00,+00.00};
objectType objectType::fprb ={+36.00,+20.15};
objectType objectType::fglt ={-52.50,-07.00};
objectType objectType::fglb ={-52.50,+07.00};
objectType objectType::fgrt ={+52.50,-07.00};
objectType objectType::fgrb ={+52.50,+07.00};
objectType objectType::fl0  ={-57.50,+00.00};
objectType objectType::fr0  ={+57.50,+00.00};
objectType objectType::ft0  ={+00.00,-39.00};
objectType objectType::fb0  ={+00.00,+39.00};
objectType objectType::ftl10={-10.00,-39.00};
objectType objectType::ftl20={-20.00,-39.00};
objectType objectType::ftl30={-30.00,-39.00};
objectType objectType::ftl40={-40.00,-39.00};
objectType objectType::ftl50={-50.00,-39.00};
objectType objectType::ftr10={+10.00,-39.00};
objectType objectType::ftr20={+20.00,-39.00};
objectType objectType::ftr30={+30.00,-39.00};
objectType objectType::ftr40={+40.00,-39.00};
objectType objectType::ftr50={+50.00,-39.00};
objectType objectType::fbl10={-10.00,+39.00};
objectType objectType::fbl20={-20.00,+39.00};
objectType objectType::fbl30={-30.00,+39.00};
objectType objectType::fbl40={-40.00,+39.00};
objectType objectType::fbl50={-50.00,+39.00};
objectType objectType::fbr10={+10.00,+39.00};
objectType objectType::fbr20={+20.00,+39.00};
objectType objectType::fbr30={+30.00,+39.00};
objectType objectType::fbr40={+40.00,+39.00};
objectType objectType::fbr50={+50.00,+39.00};
objectType objectType::flt10={-57.50,-10.00};
objectType objectType::flt20={-57.50,-20.00};
objectType objectType::flt30={-57.50,-30.00};
objectType objectType::flb10={-57.50,+10.00};
objectType objectType::flb20={-57.50,+20.00};
objectType objectType::flb30={-57.50,+30.00};
objectType objectType::frt10={+57.50,-10.00};
objectType objectType::frt20={+57.50,-20.00};
objectType objectType::frt30={+57.50,-30.00};
objectType objectType::frb10={+57.50,+10.00};
objectType objectType::frb20={+57.50,+20.00};
objectType objectType::frb30={+57.50,+30.00};
objectType objectType::ll   ={+00.00,+00.00};
objectType objectType::lr   ={+00.00,+00.00};
objectType objectType::lt   ={+00.00,+00.00};
objectType objectType::lb   ={+00.00,+00.00};
objectType objectType::p    ={+00.00,+00.00};
objectType objectType::P    ={+00.00,+00.00};
objectType objectType::ball ={+00.00,+00.00};
objectType objectType::B    ={+00.00,+00.00};
objectType objectType::G    ={+00.00,+00.00};
objectType objectType::F    ={+00.00,+00.00};

objectData::objectData():
    parameterCount(objectData::P2),
    distance(0),
    direction(0),
    distChange(0),
    dirChange(0),
    bodyFacingDir(0),
    headFacingDir(0)
{
}

objectData::objectData(double p_distance,
                       double p_direction,
                       double p_distChange,
                       double p_dirChange,
                       double p_bodyFacingDir,
                       double p_headFacingDir):
    parameterCount(objectData::P6),
    distance(p_distance),
    direction(p_direction),
    distChange(p_distChange),
    dirChange(p_dirChange),
    bodyFacingDir(p_bodyFacingDir),
    headFacingDir(p_headFacingDir)
{
}

objectData::objectData(double p_distance,
                       double p_direction,
                       double p_distChange,
                       double p_dirChange):
    parameterCount(objectData::P4),
    distance(p_distance),
    direction(p_direction),
    distChange(p_distChange),
    dirChange(p_dirChange)
{
}

objectData::objectData(double p_distance,
                       double p_direction):
    parameterCount(objectData::P2),
    distance(p_distance),
    direction(p_direction)
{
}

playerData::playerData()
{
}

playerData::playerData(double _distance, double _direction):
    objectData(_distance, _direction)
{
}

playerData::playerData(char* _teamName, double _distance, double _direction):
    objectData(_distance, _direction)
{
    teamName = new char[strlen(_teamName)+1];
    strcpy(teamName,_teamName);
}

playerData::playerData(char *_teamName,
                       int _uniform,
                       bool _goalie,
                       double _distance, double _direction,
                       double _distChange, double _dirChange,
                       double _bodyFacingDir, double _headFacingDir):
    uniform(_uniform),
    goalie(_goalie),
    objectData(_distance,_direction,_distChange,_dirChange,_bodyFacingDir, _headFacingDir)
{
    teamName = new char[strlen(_teamName)+1];
    strcpy(teamName,_teamName);
}

object::object(objectType *_type, objectData *_data):
    type(_type),
    data(_data)
{
}
