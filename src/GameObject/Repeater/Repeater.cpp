#include "Repeater.hpp"
#include "../../GameWorld/GameWorld.hpp"

Repeater::Repeater(int x, int y) : Peashooter(x, y), attackMode(false) {
    ChangeImage(IMGID_REPEATER);
}

void Repeater::Update() {
    if (isDead()) {
        return;
    }
    if (getShootInterval() == 25 && inAttM()) {
        shoot();
        negAttM();
    }
    if (getShootInterval() <= 30 && getShootInterval() > 0) {
        setShootInterval(getShootInterval()-1);
        return;
    }
    if (getShootInterval() == 0) {
        if (livingWorld->findZombie(GetX(), GetY())) {
            shoot();
            negAttM();
            setShootInterval(30);
        }
        return;
    } 
}

bool Repeater::inAttM() const {
    return attackMode;
}

void Repeater::negAttM() {
    attackMode = !attackMode;
}
