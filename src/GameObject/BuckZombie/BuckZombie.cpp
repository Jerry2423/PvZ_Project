#include "BuckZombie.hpp"
#define HP 1300

BuckZombie::BuckZombie(int x, int y) : Zombie(IMGID_BUCKET_HEAD_ZOMBIE, x, y, ANIMID_WALK_ANIM, HP) {}

void BuckZombie::Update() {
    if (isDead()) {
        return;
    }
    if (getMState() == MotionState::Move) {
        MoveTo(GetX()-1, GetY());
    }
    if (getHP() == 200) {
        ChangeImage(IMGID_REGULAR_ZOMBIE);
    }
}
