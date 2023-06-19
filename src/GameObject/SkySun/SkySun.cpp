#include "SkySun.hpp"
#include "../../utils.hpp"

void SkySun::Update() {
    if (isOnLand()) {
        decrOnLandTime();
    } else {
        MoveTo(GetX(), GetY()-2);
        decrFallingTime();
    }
}

SkySun::SkySun(int x, int y) : Sun(IMGID_SUN, x, y, LAYER_SUN,  ANIMID_IDLE_ANIM, randInt(63, 263)) {}
