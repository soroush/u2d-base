#ifndef SEE_H
#define SEE_H

#include <QList>

struct objectType
{
    double x;
    double y;
    static objectType ball ;
    static objectType B    ;
    static objectType F    ;
    static objectType G    ;
    static objectType gl   ;
    static objectType gr   ;
    static objectType fc   ;
    static objectType flt  ;
    static objectType flb  ;
    static objectType fct  ;
    static objectType fcb  ;
    static objectType frt  ;
    static objectType frb  ;
    static objectType fplt ;
    static objectType fplc ;
    static objectType fplb ;
    static objectType fprt ;
    static objectType fprc ;
    static objectType fprb ;
    static objectType fglt ;
    static objectType fglb ;
    static objectType fgrt ;
    static objectType fgrb ;
    static objectType fl0  ;
    static objectType fr0  ;
    static objectType ft0  ;
    static objectType fb0  ;
    static objectType ftl10;
    static objectType ftl20;
    static objectType ftl30;
    static objectType ftl40;
    static objectType ftl50;
    static objectType ftr10;
    static objectType ftr20;
    static objectType ftr30;
    static objectType ftr40;
    static objectType ftr50;
    static objectType fbl10;
    static objectType fbl20;
    static objectType fbl30;
    static objectType fbl40;
    static objectType fbl50;
    static objectType fbr10;
    static objectType fbr20;
    static objectType fbr30;
    static objectType fbr40;
    static objectType fbr50;
    static objectType flt10;
    static objectType flt20;
    static objectType flt30;
    static objectType flb10;
    static objectType flb20;
    static objectType flb30;
    static objectType frt10;
    static objectType frt20;
    static objectType frt30;
    static objectType frb10;
    static objectType frb20;
    static objectType frb30;
    static objectType ll;
    static objectType lr;
    static objectType lt;
    static objectType lb;
    static objectType p;
    static objectType P;
};

struct objectData
{
    enum parameterCountType{P2,P4,P6};
    parameterCountType parameterCount;
    double distance;
    double direction;
    double distChange;
    double dirChange;
    double bodyFacingDir;
    double headFacingDir;
public:
    objectData();
    objectData(double p_distance,
               double p_direction,
               double p_distChange,
               double p_dirChange,
               double p_bodyFacingDir,
               double p_headFacingDir );
    objectData(double p_distance,
               double p_direction,
               double p_distChange,
               double p_dirChange);
    objectData(double p_distance,
               double p_direction);
};


struct playerData : public objectData
{
    char* teamName;
    unsigned short uniform;
    bool goalie;
    playerData();
    playerData(double distance, double direction);
    playerData(char* _teamName, double distance, double direction);
    playerData(char* _teamName,
               int uniform,
               bool goalie,
               double distance, double direction,
               double distChange, double dirChange,
               double bodyFacingDir, double headFacingDir);
};

struct object
{
    objectType* type;
    objectData* data;
public:
    object(objectType* _type, objectData* _data);
};

struct see
{
public:
    QList<object*> seeingObjects;
    int time;
};

#endif // SEE_H
