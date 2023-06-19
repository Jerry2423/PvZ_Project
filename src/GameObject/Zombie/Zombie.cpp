#include "Zombie.hpp"

void Zombie::OnClick() {}

bool Zombie::isZombie() const {
    return true;
}

bool Zombie::isAttacker() const {
   return getMState() == MotionState::Stop || getMState() == MotionState::Move; 
}

Zombie::Zombie(ImageID image, int x, int y, AnimID anim, int hp) : GameObject(image, x, y, LAYER_ZOMBIES, 20, 80, anim) {
    setHP(hp);
    setMState(MotionState::Move);
    setAttVal(3);
}

void Zombie::collide() {
    if (getMState() == MotionState::Move) {
        setMState(MotionState::Stop);
        PlayAnimation(ANIMID_EAT_ANIM);
    }
}
