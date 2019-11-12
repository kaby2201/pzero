#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/View.hpp>

class Camera {
public:
    Camera();
    ~Camera(){};

    void follow(sf::Vector2f center);

    void setCenter(sf::Vector2f center);

    void zoom(float factor);

    bool isTrue();

private:
    sf::Vector2f oldCenter;
    sf::Vector2f center;
    sf::View view;
};


#endif //CAMERA_H
