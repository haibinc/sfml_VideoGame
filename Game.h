//
// Created by Haibin Cao on 11/19/22.
//

#ifndef VIDEOGAME_GAME_H
#define VIDEOGAME_GAME_H
#include "Application.h"
#include "Player.h"

class Game : public Application
{
private:
    TextureHolder mTextures;
    Player player;
private:
    void loadTextures();
    void buildScene();
public:
    Game();
};


#endif //VIDEOGAME_GAME_H
