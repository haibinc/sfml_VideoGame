//
// Created by Haibin Cao on 11/18/22.
//

#include "Player.h"
Player::Player()
{

}

Player::Player(playerType mType)
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
        case Hollow:
        {
            mTextures.load(Textures::Hollow, "Hollow.png");
            return Textures::Hollow;
        }
    }
}

void Player::setTexture(playerType mType)
{
    player.setTexture(mTextures.get(toTextureID(mType)));
    initAnimations(mType);
}

void Player::initAnimations(playerType mType)
{
    switch(mType)
    {
        case Spidey :
        {
            std::cout << "mType: " << mType << std::endl;
            m_Animations["walk"].create(6, 0, 0.06f, sf::Vector2u(80,80), player, 0);
            m_Animations["up"].create(5, 6, 0.08f, sf::Vector2u(80,80), player, 5);
            m_Animations["down"].create(5, 0, 0.08f, sf::Vector2u(80,80), player, 5);
            m_Animations["idle"].create(7, 0, 0.2f, sf::Vector2u(80,80), player, 8);
            break;
        }
        case Hollow :
            std::cout << "mType: " << mType << std::endl;
            m_Animations["idle"].create(6, 0, 0.2f, sf::Vector2u(128,128), player, 8);
            m_Animations["walk"].create(8, 0, 0.06f, sf::Vector2u(128,128), player, 0);
            m_Animations["dash"].create(1, 3, 0.04f, sf::Vector2u(128,128), player, 2);
            m_Animations["up"].create(6, 6, 0.08f, sf::Vector2u(128,128), player, 5);
            m_Animations["down"].create(6, 0, 0.08f, sf::Vector2u(128,128), player, 5);
            break;
    }
}

void Player::animate()
{
    if(mVelocity.x > 0 && mVelocity.x < 20)
    {
        player.setScale(sf::Vector2f(1.0,1.0));
        m_Animations["walk"].updateAnimation();
    }
    else if(mVelocity.x < 0 && mVelocity.x > -20)
    {
        player.setScale(sf::Vector2f(-1.0,1.0));
        m_Animations["walk"].updateAnimation();
    }
    else if(mVelocity.x >= 20)
    {
        player.setScale(sf::Vector2f(1.0,1.0));
        m_Animations["dash"].updateAnimation();
    }
    else if(mVelocity.x <= -20)
    {
        player.setScale(sf::Vector2f(-1.0,1.0));
        m_Animations["dash"].updateAnimation();
    }
    else if(mVelocity.x == 0 && mVelocity.y == 0)
    {
        m_Animations["idle"].updateAnimation();
    }

    if(mVelocity.y > 0)
    {
        m_Animations["up"].updateAnimation();
    }
    else if(mVelocity.y < 0)
    {
        m_Animations["down"].updateAnimation();
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
        mVelocity.x = -10.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        mVelocity.x = 10.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        mVelocity.x = 20.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        mVelocity.x = -20.f;
    player.move(mVelocity);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(player);
}