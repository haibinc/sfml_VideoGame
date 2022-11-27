//
// Created by Haibin Cao on 11/18/22.
//

#include "Animation.h"

//Creates an array of sf::IntRect the size of how many frames there are for the selected animation
//We will implement the Mommys. I swear on my life.
Animation::Animation()
{

}

Animation::~Animation()
{
    delete []m_textureRect;
}

Animation::Animation(unsigned int rowFrames, unsigned int colFrames,  float animationSpeed, sf::Vector2u spriteSize, sf::Sprite& sprite, unsigned int rowStart)
{

}

void Animation::create(unsigned int rowFrames, unsigned int colFrames, float animationSpeed, sf::Vector2u spriteSize, sf::Sprite &sprite, unsigned int rowStart)
{
    sprite.setOrigin(sf::Vector2f(spriteSize.x/2, spriteSize.y/2));
    m_updateTime = animationSpeed;
    m_Sprite = &sprite;
    m_frameCount = rowFrames;
    m_textureRect = new sf::IntRect[rowFrames];
    CutFrames(rowFrames, colFrames, rowStart, spriteSize);
}

void Animation::updateAnimation()
{
    while(clock.getElapsedTime().asSeconds() < m_updateTime)
    {
    }
    if(++m_currentFrame >= m_frameCount)
    {
        m_currentFrame = 0;
    }
    m_Sprite->setTextureRect(m_textureRect[m_currentFrame]);
    clock.restart();
}

void Animation::CutFrames(const unsigned int &rowFrames, const unsigned int &colFrames, const unsigned int &rowStart, const sf::Vector2u &spriteSize)
{
    if(colFrames > 0)
    {
        int counter = colFrames;
        for (int i = 0; i < rowFrames; ++i)
        {
            m_textureRect[i] = sf::IntRect((spriteSize.x * counter), spriteSize.y * rowStart, spriteSize.x, spriteSize.y);
            counter++;
        }
    }
    else
    {
        for (int i = 0; i < rowFrames; ++i) {
            m_textureRect[i] = sf::IntRect((spriteSize.x * i), spriteSize.y * rowStart, spriteSize.x, spriteSize.y);
        }
    }
}