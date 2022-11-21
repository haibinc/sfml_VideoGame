//
// Created by Haibin Cao on 11/17/22.
//

#ifndef VIDEOGAME_COMPONENTS_H
#define VIDEOGAME_COMPONENTS_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "Updater.h"

class Components : public sf::Drawable, public EventHandler, public Updater
{

};


#endif //VIDEOGAME_COMPONENTS_H
