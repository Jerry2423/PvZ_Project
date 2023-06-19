#include "Explosion.hpp"
#define MAX_HP 4000
#define MAX_ATT_VAL 1300
#define TIMER 3

Explosion::Explosion(int x, int y) : Attacker(IMGID_EXPLOSION, x, y, LAYER_PROJECTILES, 3*LAWN_GRID_WIDTH, 3*LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION), timer(TIMER) {
    setHP(MAX_HP);
    setAttVal(MAX_ATT_VAL);
}

int Explosion::getTime() const {
    return timer;
}

void Explosion::setTime(int t) {
    timer = t;
}

void Explosion::Update() {
    if (getTime() == 0) {
        setHP(0);
    } else  {
        setTime(getTime()-1);
    }
}

// bool Explosion::isPlant() const {
//     return true;
// }
//
// bool Explosion::isAttacker() const {
//     return true;
// }
//
// void Explosion::OnClick() {}
