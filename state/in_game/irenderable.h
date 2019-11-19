#ifndef IRENDERABLE_H
#define IRENDERABLE_H


#include <SFML/Graphics/RenderTarget.hpp>
#include "iobject.h"

class IRenderable : virtual public IObject
{
public:
    IRenderable(){}
    virtual ~IRenderable(){}

    virtual void draw(sf::RenderTarget& target, float alpha){}
    virtual void drawStationary(sf::RenderTarget& target){}
};


#endif //PZERO_IRENDERABLE_H
