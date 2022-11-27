//
// Created by Haibin Cao on 11/22/22.
//

#ifndef VIDEOGAME_POSITION_CPP
#define VIDEOGAME_POSITION_CPP
#include "Position.h"

template<class T, class S>
void Position::left(const T &obj1, S &obj2, float spacing)
{
    sf::FloatRect b1 = obj1.getGlobalBounds();
    sf::FloatRect b2 = obj2.getGlobalBounds();
    obj2.setPosition(b1.left - b2.width - spacing, b1.top);
}

template<class T, class S>
void Position::right(const T &obj1, S &obj2, float spacing)
{

}

template<class T, class S>
void Position::center(const T &obj1, S &obj2, float spacing)
{

}

template<class T, class S>
void Position::bottom(const T &obj1, S &obj2, float spacing)
{

}

#endif