//
// Created by Haibin Cao on 11/19/22.
//

#include "Entity.h"

void Entity::setVelocity(sf::Vector2f mVelocity)
{
    this->mVelocity = mVelocity;
}

void Entity::setVelocity(float vX, float vY)
{
    mVelocity.x = vX;
    mVelocity.y = vY;
}

sf::Vector2f Entity::getVelocity() const
{
    return mVelocity;
}
