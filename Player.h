//
// Created by Haibin Cao on 11/18/22.
//

#ifndef VIDEOGAME_PLAYER_H
#define VIDEOGAME_PLAYER_H
#include <iostream>
#include "Components.h"
#include "playerType.h"
#include "Animation.h"
#include "Entity.h"
#include "ResourceHolder.h"
#include "unordered_map"

class Player : public Components, public Entity
{
private:
    playerType mType;
    sf::Sprite player;
    TextureHolder mTextures;
    std::unordered_map<std::string, Animation> m_Animations;
public:
    Player();
    Player(playerType mType);
public:
    Textures::ID toTextureID(playerType mType);
    void setTexture(playerType mType);
    void initAnimations(playerType mType);
    void animate();
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //VIDEOGAME_PLAYER_H
