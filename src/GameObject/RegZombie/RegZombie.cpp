#include "RegZombie.hpp"

RegZombie::RegZombie(int x, int y) : Zombie(IMGID_REGULAR_ZOMBIE, x, y, ANIMID_WALK_ANIM, 200) {}

void RegZombie::Update() {
    if (isDead()) {
        return;
    }
    if (getMState() == MotionState::Move) {
        MoveTo(GetX()-1, GetY());
    }
}
