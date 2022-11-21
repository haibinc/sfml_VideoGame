//
// Created by Haibin Cao on 11/18/22.
//

#include "Player.h"
Player::Player()
:Player(Spidey)
{
    player.setTexture(mTextures.get(toTextureID(mType)));
    initAnimations();
}

Player::Player(playerType mType)
:mType(mType)
{
}

Textures::ID Player::toTextureID(playerType mType)
{
    switch(mType)
    {
        case Spidey:
        {
            mTextures.load(Textures::Spidey, "Spider-Man.png");
            return Textures::Spidey;
        }
        case Batman:
        {
            mTextures.load(Textures::Batman, "Batman.png");
            return Textures::Batman;
        }
        case Hollow:
        {
            mTextures.load(Textures::Hollow, "Hollow.png");
            return Textures::Hollow;
        }
    }
}

void Player::setTexture(playerType mType)
{
    this->mType = mType;
    player.setTexture(mTextures.get(toTextureID(mType)));
}

void Player::initAnimations()
{
    switch(mType)
    {
        case Spidey :
        {
            m_Animations["walk"].create(6, 0, 0.08f, sf::Vector2u(80,80), player, 0);
            m_Animations["idle"].create(7, 0, 0.08f, sf::Vector2u(80,80), player, 8);
        }
        case Batman :
            break;
        case Hollow :
            m_Animations["idle"].create(6, 0, 0.08f, sf::Vector2u(100,100), player, 8);
            break;
    }
}

void Player::animate()
{
    if(mVelocity.x > 0)
    {
        player.setScale(sf::Vector2f(1.0,1.0));
        m_Animations["walk"].updateAnimation();
    }
    else if(mVelocity.x < 0)
    {
        player.setScale(sf::Vector2f(-1.0,1.0));
        m_Animations["walk"].updateAnimation();
    }
    else if(mVelocity.x == 0 && mVelocity.y == 0)
    {
        m_Animations["idle"].updateAnimation();
    }
}

void Player::eventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Player::update()
{
    animate();
    mVelocity = sf::Vector2f{0,0};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        mVelocity.y = -5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        mVelocity.y = 5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        mVelocity.x = -5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        mVelocity.x = 5.f;
    player.move(mVelocity);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(player);
}