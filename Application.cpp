//
// Created by Haibin Cao on 11/17/22.
//

#include "Application.h"

Application::Application()
:Application({1920, 1080}, "Title")
{

}

Application::Application(sf::VideoMode videoMode, const std::string &title)
: videoMode(videoMode), title(title)
{

}

void Application::addComponents(Components &component)
{
    components.push_back(&component);
}

void Application::run()
{
    sf::RenderWindow window(videoMode, title);
    window.setFramerateLimit(60);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                window.close();
            }
            for (EventHandler *c : components)
            {
                c->eventHandler(window, event);
            }
        }
        window.clear();
        for (Updater *c : components)
        {
            c->update();
        }
        for (sf::Drawable *c : components)
        {
            window.draw(*c);
        }
        window.display();
    }
}
