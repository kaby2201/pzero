#ifndef IOBJECT_H
#define IOBJECT_H


class IObject
{
public:
    IObject(){aLive=true;}
    virtual ~IObject(){}

    virtual void update(){}

    virtual void respawn(){aLive=true;}
    virtual void kill(){aLive=false;}

    bool isAlive(){return aLive;}

protected:
    bool aLive;
};


#endif //PZERO_IOBJECT_H
