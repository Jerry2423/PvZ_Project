#include "FlowerSun.hpp"


FlowerSun::FlowerSun(int x, int y) : Sun(IMGID_SUN, x, y, LAYER_SUN, ANIMID_IDLE_ANIM, 12 ), v_y(4) {}


void FlowerSun::deltaVy() {
    v_y += accel;
}

void FlowerSun::Update() {
    if (isOnLand()) {
        decrOnLandTime();
    } else {
        decrFallingTime();
        MoveTo(GetX() + v_x, GetY() + v_y);
        deltaVy();
    }
}
