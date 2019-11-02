#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {

    bool alpha = false;
    sf::RenderWindow window(sf::VideoMode(800,800),"test");
    window.setFramerateLimit(60);
    sf::CircleShape shape;
    sf::Music music;
    if (!music.openFromFile("C:\\Users\\Mr. Engineer\\Desktop\\Algorithms\\SFML\\music.ogg"))
    {std::cout<<"ERROR"<<std::endl;}
    music.setVolume(20);
    shape.setRadius(20.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(400,400);
    sf::Vector2f localPostion;


    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right)
                    localPostion.x = sf::Mouse::getPosition(window).x;
                localPostion.y = sf::Mouse::getPosition(window).y;
                {
                    if (shape.getGlobalBounds().contains(localPostion)) {
                        if (!alpha) {
                            music.play();
                            alpha = true;
                        } else if (alpha) {
                            music.pause();
                            alpha = false;
                        }
                    }
                }
            }
            if(event.type == sf::Event::MouseWheelScrolled)
            {
                if(event.mouseWheelScroll.wheel == sf::Mouse::Wheel::VerticalWheel)
                {
                    std::cout<<"Wheel moved!"<<std::endl;
                    music.setVolume(music.getVolume()+3);
                }
            }

            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Space) {
                    if (!alpha) {
                        music.play();
                        alpha = true;
                    } else if (alpha) {
                        music.pause();
                        alpha = false;
                    }
                }
            }

        }


        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}