#include <state/in_game/include/Camera.h>
#include "state/in_game/include/Constants.h"

Camera::Camera(){
    mView = sf::View(sf::FloatRect(mCenter.x, mCenter.y, SCREEN_WIDTH, SCREEN_HEIGHT));
}

Camera::~Camera()
{
    //dtor
}

void Camera::follow(sf::Vector2f center){
    mOldCenter = mCenter;
    mCenter = center;
    mView.setCenter(mCenter);
}
