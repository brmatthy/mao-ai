//
// Created by brent on 1/10/22.
//



#include <iostream>
#include "game/ImmutableCard.h"

int main(){
    ImmutableCard card = ImmutableCard(HEARTS, ACE);
    std::cout << card;
}