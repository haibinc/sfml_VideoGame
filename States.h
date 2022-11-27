//
// Created by Haibin Cao on 11/22/22.
//

#ifndef VIDEOGAME_STATES_H
#define VIDEOGAME_STATES_H
#include <map>
#include "statesEnum.h"
class States
{
private:
    std::map<statesEnum, bool> map;
    void load();
public:
    States();
    bool checkState(statesEnum state) const;
    void enableState(statesEnum state);
    void disableState(statesEnum state);
    void setState(statesEnum state, bool value);
    void toggleState(statesEnum state);
};


#endif //VIDEOGAME_STATES_H
