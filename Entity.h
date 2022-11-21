//
// Created by Haibin Cao on 11/19/22.
//

#ifndef VIDEOGAME_ENTITY_H
#define VIDEOGAME_ENTITY_H
#include "SFML/Graphics.hpp"

class Entity
{
public:
    sf::Vector2f mVelocity;
    void setVelocity(sf::Vector2f mVelocity);
    void setVelocity(float vX, float vY);
    sf::Vector2f getVelocity() const;
};


#endif //VIDEOGAME_ENTITY_H
