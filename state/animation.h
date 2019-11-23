//
// Created by ALI on 03/11/2019.
//

#ifndef PZERO_ANIMATION_H
#define PZERO_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class animation {
public: //public for funksjoner (for å holde orden)
    animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime); //Konstruktøren skal ha en Texture, imageCount skal inneholde bildene

// , switchenTime bestemmer tiden hver animasjon tar
    void Update(int row, float deltaTime, bool faceRight, bool standStill); //Row hvilken rad av animasjonen du vil ha, Delta time tiden mellom forrige og denne animasjonen(brukt for at alle datamaskiner skal ha samme hastighet gjennom animasjonen)

public: //public for variabler (orden)
    sf::IntRect uvRect; //rektangelet som skal vise animasjonen

private:
    sf::Vector2u imageCount;  //Antall bilder i raden på spritesheet;
    sf::Vector2u currentImage;
    float totalTime;  //disse bestemmer hvor fort animasjonen skal gå
    float switchTime; //tiden den bruker på å bytte mellom hvert bilde
    float speed;
};
#endif //PZERO_ANIMATION_H
