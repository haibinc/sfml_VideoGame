//
// Created by Haibin Cao on 11/19/22.
//

#ifndef VIDEOGAME_RESOURCEHOLDER_H
#define VIDEOGAME_RESOURCEHOLDER_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "ResourceIdentifier.h"
#include <map>
#include <string>
#include <memory>

template <class Identifier, class Resource>
class ResourceHolder
{
private:
    static std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
public:
    ResourceHolder();
    static void load(Identifier id, const std::string& fileName);
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;
};

#include "ResourceHolder.cpp"
#endif //VIDEOGAME_RESOURCEHOLDER_H
