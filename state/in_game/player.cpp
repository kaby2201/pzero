#include "player.h"

Player::~Player() {

}

Player::Player(SpriteInfo &info, sf::Vector2f pos) : SpriteObject(info, pos) {

}

bool Player::onContactBegin(std::weak_ptr<Icollideable> object, bool fromLeft, bool fromTop) {
    return false;
}

void Player::update() {

}

void Player::draw(sf::RenderTarget &target, float alpha) {

}

void Player::handleEvent(sf::Event &event) {

}

void Player::respawn(sf::Vector2f post) {

}
