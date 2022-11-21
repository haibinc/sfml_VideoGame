//
// Created by Haibin Cao on 11/17/22.
//

#ifndef VIDEOGAME_APPLICATION_H
#define VIDEOGAME_APPLICATION_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Components.h"

class Application
{
private:
    std::vector<Components*> components;
    sf::VideoMode videoMode;
    std::string title;
public:
    Application();
    Application(sf::VideoMode videoMode, const std::string& title);
    void addComponents(Components& component);
    void run();
};


#endif //VIDEOGAME_APPLICATION_H
