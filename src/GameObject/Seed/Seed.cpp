#include "Seed.hpp"
#include "../../GameWorld/GameWorld.hpp"

void Seed::Update() {}

bool Seed::isZombie() const {
    return false;
}

bool Seed::canClick() const {
    return livingWorld->getSeedType() == SeedType::Default; 
}

bool Seed::isDead() const {
    return false;
}

Seed::Seed(ImageID image, int x, int y, int price, int coolDownTime) : GameObject(image, x, y, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION), price(price), coolDownTime(coolDownTime) {}

int Seed::getPrice() const {
    return price;
}

int Seed::getCoolDownTime() const {
    return coolDownTime;
}
