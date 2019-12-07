//
// Created by ALI on 03/11/2019.
//
#include "animation.h"
#include <SFML/Graphics.hpp>

animation::animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0; //bestemmer hvilket bilde vi får tilgang til i en rad.

    //   uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.width = 64;
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

void animation::Update(int row, float deltaTime, bool faceRight, bool standStill) {
    currentImage.y = row;     //høyden bestemmer hvilken rad vi er på (på character spriten)
    totalTime += deltaTime;

    if(totalTime >= switchTime){
        totalTime -= switchTime;         //(kunne satt den


        if (standStill) {
            currentImage.x = 0;
        } else {
            currentImage.x++;
            if(currentImage.x >= 8) {      //Starter animasjonen på nytt (setter x posision tilbake til 0).
                currentImage.x = 0;
            }
        }
    }

    uvRect.top = currentImage.y * uvRect.height;
    if(faceRight){
        uvRect.left = currentImage.x * abs(uvRect.width);        //bestemmer hvor langt vi har kommet på spriten
        uvRect.width = abs(uvRect.width);
    } else {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);        //bestemmer hvor langt vi har kommet på spriten
        uvRect.width = -abs(uvRect.width);
    }
}


