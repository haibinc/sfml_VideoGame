//
// Created by Haibin Cao on 11/22/22.
//

#include "MouseEvents.h"

template<class T>
bool MouseEvents::isHover(const T &obj, const sf::RenderWindow &window)
{
    sf::Vector2f m_Pos = sf::Vector2f(sf::Mouse::getPosition(window));
    return obj.getGlobalBounds().contain(m_Pos);
}

template<class T>
bool MouseEvents::isClick(const T &obj, const sf::RenderWindow &window)
{
    return isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
