//
// Created by Haibin Cao on 11/28/22.
//

#ifndef VIDEOGAME_STATEMACHINE_H
#define VIDEOGAME_STATEMACHINE_H
#include <unordered_map>
#include <stack>
#include "States.h"
class StateMachine
{
private:
    std::stack<std::unique_ptr<States>> state;
public:
    void addState(std::unique_ptr<States>states);
    void deleteState();
};


#endif //VIDEOGAME_STATEMACHINE_H
