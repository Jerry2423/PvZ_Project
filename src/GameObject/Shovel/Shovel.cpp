#include "Shovel.hpp"
#include "../../GameWorld/GameWorld.hpp"

Shovel::Shovel(int x, int y) : GameObject(IMGID_SHOVEL, x, y, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION) {}

void Shovel::Update() {}

void Shovel::OnClick() {
    if (livingWorld->getSeedType() == SeedType::Default) {
        livingWorld->setSeedType(SeedType::Shovel);
    } else if (livingWorld->getSeedType() == SeedType::Shovel) {
        livingWorld->setSeedType(SeedType::Default);
    }
}

bool Shovel::isDead() const {
    return false;
}

bool Shovel::isZombie() const {
    return false;
}
