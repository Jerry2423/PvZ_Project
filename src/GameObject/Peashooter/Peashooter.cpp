#include "Peashooter.hpp"
#include <iostream>
#include "../../utils.hpp"
#include "../../GameWorld/GameWorld.hpp"
using std::cout; using std::endl;
/*
change a plant:
from plant file
image
hp
plot
*/

Peashooter::Peashooter(int x, int y) : Plant(IMGID_PEASHOOTER, x, y, 300) ,
     shootInterval(0){}


int Peashooter::getShootInterval() const {
    return shootInterval;
}

void Peashooter::setShootInterval(int interval) {
    shootInterval = interval;
}



void Peashooter::Update() {
    if (isDead()){
        return;
    }
    if (getShootInterval() <= 30 && getShootInterval() > 0) {
        setShootInterval(getShootInterval()-1);
        return;
    }
    if (getShootInterval() == 0) {
        if (livingWorld->findZombie(GetX(), GetY())) {
            shoot();
            setShootInterval(30);
        }
    }
}

void Peashooter::shoot() {
    livingWorld->addPea(GetX()+30, GetY()+20);
}
