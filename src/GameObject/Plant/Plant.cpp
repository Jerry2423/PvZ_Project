#include "Plant.hpp"
#include "../../GameWorld/GameWorld.hpp"

// int Plant::getHP() const {
//     return hp;
// }
//
// void Plant::setHP(int k) {
//     hp = k;
// }

bool Plant::isPlant() const {
    return true;
}
void Plant::OnClick() {
    if (livingWorld->getSeedType() == SeedType::Shovel) {
        setHP(0);
        livingWorld->setSeedType(SeedType::Default);
    }
}

// bool Plant::isDead() const {
//     return hp <= 0;
// }

bool Plant::isZombie() const {
    return false;
}

Plant::Plant(ImageID image, int x, int y, int hp) : GameObject(image, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM) {
    setHP(hp);
}

