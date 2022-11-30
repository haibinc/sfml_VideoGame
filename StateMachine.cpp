//
// Created by Haibin Cao on 11/28/22.
//

#include "StateMachine.h"

void StateMachine::addState(std::unique_ptr<States> states)
{
    state.push(std::move(states));
}

void StateMachine::deleteState()
{
    if(!state.empty())
    {
        state.pop();
    }

}
