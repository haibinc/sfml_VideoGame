//
// Created by Haibin Cao on 11/18/22.
//

#ifndef VIDEOGAME_ANIMATION_H
#define VIDEOGAME_ANIMATION_H
#include "SFML/Graphics.hpp"
#include <iostream>
class Animation
{
private:
    unsigned int m_currentFrame = 0;
    unsigned int m_frameCount = 0;
    float m_updateTime = 0.f;
    sf::IntRect* m_textureRect = nullptr;
    sf::Sprite* m_Sprite = nullptr;

private:
    void CutFrames(const unsigned int& rowFrames, const unsigned int& colFrames, const unsigned& rowStart, const sf::Vector2u& spriteSize);
public:
    Animation();
    ~Animation();
    Animation(unsigned int rowFrames, unsigned int colFrames, float animationSpeed, sf::Vector2u spriteSize, sf::Sprite& sprite, unsigned int rowStart = 0);

public:
    void updateAnimation();
    void create(unsigned int rowFrames, unsigned int colFrames, float animationSpeed, sf::Vector2u spriteSize, sf::Sprite& sprite, unsigned int rowStart = 0);
};


#endif //VIDEOGAME_ANIMATION_H
