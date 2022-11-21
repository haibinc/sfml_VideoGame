//
// Created by Haibin Cao on 11/17/22.
//

#ifndef VIDEOGAME_EVENTHANDLER_H
#define VIDEOGAME_EVENTHANDLER_H
#include <SFML/Graphics.hpp>

class EventHandler
{
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
};


#endif //VIDEOGAME_EVENTHANDLER_H
