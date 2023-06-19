#include "SunFlower.hpp"
#include "../../utils.hpp"
#include "../../GameWorld/GameWorld.hpp"

SunFlower::SunFlower(int x, int y) : Plant(IMGID_SUNFLOWER, x, y, 300), genSunTime(randInt(30, 600)),
    first(true), genInterval(600), timer(0){}

void SunFlower::genSun() {
    //sun from flower need to be modified
    livingWorld->genSun(SunType::GroundSun, GetX(), GetY());
}

int SunFlower::getTime() const {
    return timer;
}

void SunFlower::setTime(int t) {
    timer = t;
}

int SunFlower::getInterval() const {
    return genInterval;
}

void SunFlower::setInterval(int interval) {
    genInterval = interval;
}

int SunFlower::getGenSunTime() const {
    return genSunTime;
}

bool SunFlower::isFirst() const {
    return first;
}

void SunFlower::negFirst() {
    first = !first;
}


void SunFlower::Update() {
    if (isDead()){
        return;
    }
    if (getGenSunTime() == getTime() && isFirst()) {
        genSun();
        negFirst();
    } else if (getInterval() == 0 && !isFirst()) {
        genSun();
        setInterval(600);
    }
    setTime(getTime()+1);
    if (!isFirst()) {
        setInterval(getInterval()-1);
    }
}
