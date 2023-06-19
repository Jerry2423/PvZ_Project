#include "PoleVaultZombie.hpp"
#include "iostream"
#include "../../GameWorld/GameWorld.hpp"
#define HP 340
#define TIME 42
using std::cout;
using std::endl;

PoleVaultZombie::PoleVaultZombie(int x, int y) : Zombie(IMGID_POLE_VAULTING_ZOMBIE, x, y, ANIMID_RUN_ANIM, HP), jumpTimer(TIME) {
    setMState(MotionState::Run);
}

void PoleVaultZombie::Update() {
    if (isDead()) {
        return;
    }
    
    if (getMState() == MotionState::Run) {
        // cout <<"running"<< endl;
        MoveTo(GetX()-40, GetY());
        if (livingWorld -> collWithPlant(shared_from_this())) {
            // cout << "collide!" << endl;
            setMState(MotionState::Jump); //jumpting
            PlayAnimation(ANIMID_JUMP_ANIM);
        } else {
            MoveTo(GetX()-2, GetY());
        }
        MoveTo(GetX()+40, GetY()); 
    }

    if (getMState() == MotionState::Jump) {
        // cout << "jumping" << endl;
        if (getJumpTime() == 0) {
            MoveTo(GetX()-150, GetY());
            setMState(MotionState::Move);
            PlayAnimation(ANIMID_WALK_ANIM);
        } else {
            setJumpTime(getJumpTime()-1);
        }
        return;
    }

    if (getMState() == MotionState::Move) {
        MoveTo(GetX()-1, GetY());
        return;
    }
}

int PoleVaultZombie::getJumpTime() const {
    return jumpTimer;
}

void PoleVaultZombie::setJumpTime(int t) {
    jumpTimer = t;
}
