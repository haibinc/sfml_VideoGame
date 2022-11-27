//
// Created by Haibin Cao on 11/22/22.
//

#ifndef VIDEOGAME_MOUSEEVENTS_H
#define VIDEOGAME_MOUSEEVENTS_H
#include "SFML/Graphics.hpp"

class MouseEvents
{
public:
    template<class T>
    static bool isHover(const T& obj, const sf::RenderWindow& window);
    template<class T>
    static bool isClick(const T& obj, const sf::RenderWindow& window);
};


#endif //VIDEOGAME_MOUSEEVENTS_H
