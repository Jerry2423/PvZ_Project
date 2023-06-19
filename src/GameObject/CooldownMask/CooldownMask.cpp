#include "CooldownMask.hpp"

void CooldownMask::Update() {
   if (getTime() > 0) {
       setTimer(getTime()-1);
   } 
}
void CooldownMask::OnClick() {}

bool CooldownMask::isZombie() const {
    return false;
}

bool CooldownMask::isDead() const {
    return timer <= 0;
}

CooldownMask::CooldownMask(int x, int y, int cooldownTime) : GameObject(IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50, 70, ANIMID_NO_ANIMATION), timer(cooldownTime) {}

int CooldownMask::getTime() const {
    return timer;
}

void CooldownMask::setTimer(int t) {
    timer = t;
}
