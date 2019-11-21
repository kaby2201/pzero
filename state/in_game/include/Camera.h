#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/View.hpp>

class Camera
{
    public:
        Camera();
        ~Camera();

        void follow(sf::Vector2f center);
        sf::Vector2f getCenter(){return mCenter;}
        sf::View& getView(){return mView;}
private:
        sf::Vector2f mOldCenter; // to keep track of change
        sf::Vector2f mCenter;
        sf::View mView;
};

#endif // CAMERA_H
