//
// Created by Haibin Cao on 11/19/22.
//

#ifndef VIDEOGAME_RESOURCEIDENTIFIER_H
#define VIDEOGAME_RESOURCEIDENTIFIER_H
namespace Textures
{
    enum ID
    {
        Spidey,
        Hollow,
        Strawberry,
        Scientific,
        Goth,
        Firewomen
    };
}

namespace Font
{
    enum ID
    {

    };
}

template <class Identifier, class Resource>
class ResourceHolder;

//sets ResourceHolder<Textures::ID, sf::Texture> to textureHolder, so I don't have to type that shit
typedef ResourceHolder<Textures::ID, sf::Texture> TextureHolder;
//typedef ResourceHolder<Fonts::ID, sf::Font> FontHolder;
//typedef ResourceHolder<Sounds::ID, sf::SoundBuffer> SoundHolder;

#endif //VIDEOGAME_RESOURCEIDENTIFIER_H
