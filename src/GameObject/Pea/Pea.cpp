#include "Pea.hpp"

Pea::Pea(int x, int y) : Attacker(IMGID_PEA, x, y, LAYER_PROJECTILES, 28, 28, ANIMID_NO_ANIMATION) {
    setHP(3);
    setAttVal(20);
}

void Pea::Update() {
    if (isDead()) {
        return;
    }
    MoveTo(GetX()+8, GetY());
    if (GetY() >= WINDOW_WIDTH) {
        setHP(0);
    }
}

// bool Pea::isPlant() const {
//     return true;
// }
//
// bool Pea::isAttacker() const {
//     return true;
// }
//
// void Pea::OnClick() {}
