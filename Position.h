//
// Created by Haibin Cao on 11/22/22.
//

#ifndef VIDEOGAME_POSITION_H
#define VIDEOGAME_POSITION_H
#include "SFML/Graphics.hpp"

class Position
{
public:
    template<class T, class S>
    static void left(const T& obj1, S& obj2, float spacing = 0);
    template<class T, class S>
    static void right(const T& obj1, S& obj2, float spacing = 0);
    template<class T, class S>
    static void center(const T& obj1, S& obj2, float spacing = 0);
    template<class T, class S>
    static void bottom(const T& obj1, S& obj2, float spacing = 0);
};

#include "Position.cpp"
#endif //VIDEOGAME_POSITION_H
