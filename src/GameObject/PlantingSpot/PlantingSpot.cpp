#include "PlantingSpot.hpp"
#include "../../GameWorld/GameWorld.hpp"

PlantingSpot::PlantingSpot(int x, int y) : GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION) {};

void PlantingSpot::Update() {}

void PlantingSpot::OnClick() {
    // if (/* another rabit is dead? i.e there is sth in the hand*/) {
    //     //create the corresponding game object and push it into the world!
    //     // then make the mark bunny alive again.
    // } 
    switch (livingWorld->getSeedType()) {
        case SeedType::Sunflower:
            //plant Sunflower
            livingWorld->addObject(SeedType::Sunflower, GetX(), GetY());
            break;
        case SeedType::Peashooter:
            //plant Peashooter
            livingWorld->addObject(SeedType::Peashooter, GetX(), GetY());
            break;
        case SeedType::Wallnut:
            livingWorld->addObject(SeedType::Wallnut, GetX(), GetY());
            break;
        case SeedType::Cherry:
            livingWorld->addObject(SeedType::Cherry, GetX(), GetY());
            break;
        case SeedType::Repeater:
            livingWorld->addObject(SeedType::Repeater, GetX(), GetY());
            break;
        default:
            break;
    }
    if (livingWorld->getSeedType() != SeedType::Shovel) {
        livingWorld->setSeedType(SeedType::Default);
    }
    // livingWorld->SetSun(livingWorld->GetSun()+100);

}

bool PlantingSpot::isDead() const {
    return false;
}

bool PlantingSpot::isZombie() const {
    return false;
}
