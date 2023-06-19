#include "Cherry.hpp"
#include "../../utils.hpp"
#include "../../GameWorld/GameWorld.hpp"
#define TOTALHP 4000
#define TIMER 15
/*
change a plant:
from plant file
image
hp
plot
*/



Cherry::Cherry(int x, int y) : Plant(IMGID_CHERRY_BOMB, x, y, TOTALHP)
     , timer(TIMER){}





void Cherry::Update() {
    if (isDead()){
        return;
    }
    if (getTime() == 0) {
        setHP(0);
        livingWorld->addExplosion(GetX(), GetY()); 
    } else {
        setTime(getTime()-1);
    }
}


int Cherry::getTime() const {
    return timer;
}

void Cherry::setTime(int t) {
    timer = t;
}
