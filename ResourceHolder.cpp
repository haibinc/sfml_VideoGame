//
// Created by Haibin Cao on 11/19/22.
//
#ifndef VIDEOGAME_RESOURCEHOLDER_CPP
#define VIDEOGAME_RESOURCEHOLDER_CPP
#include "ResourceHolder.h"
template <class Identifier, class Resource>
ResourceHolder<Identifier, Resource>::ResourceHolder()
{
}


/*
 * Wraps the "Resource" (texture/sound/font) in a std::unique_ptr
 * The std::unique_ptr manages the new Resource
 * The assert makes sure that the second statment is true otherwise the program is interrupted
 * So, i.e. if you tried you load two of the same Spider-Man.png, then assert kicks in
 */
template <class Identifier, class Resource>
void ResourceHolder<Identifier, Resource>::load(Identifier id, const std::string &fileName)
{
    std::unique_ptr<Resource> resource(new Resource);
    resource->loadFromFile(fileName);
    if(!resource->loadFromFile(fileName))
    {
        throw std::runtime_error("ResourceHolder::load failed to load " + fileName);
    }
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

/*
 * This finds the sf::Texture in the map and returns an iterator to the found element
 * Then we dereference the std_unique_ptr and then again to get the texture
 * The assert is to make sure that the id does exist
 * Without the assert we would have returned some random thing with *found->second
 */
template <class Identifier, class Resource>
Resource& ResourceHolder<Identifier, Resource>::get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}

/*
 * This is the same function as above except it returns a const sf::Texture that we can not change
 * The assert is to make sure that the id does exist
 * Without the assert we would have returned some random thing with *found->second
 */
template <class Identifier, class Resource>
const Resource &ResourceHolder<Identifier, Resource>::get(Identifier id) const
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}
#endif