#include "SunFlowerSeed.hpp"
#include "../../GameWorld/GameWorld.hpp"

SunFlowerSeed::SunFlowerSeed(int x, int y) : Seed(IMGID_SEED_SUNFLOWER, x, y, 50, 240) {}

void SunFlowerSeed::OnClick() {
    if (canClick() && livingWorld->GetSun() >= 50) {
        livingWorld->addSun(-50);
        livingWorld->addCoolDownMask(GetX(), GetY(), getCoolDownTime());
        livingWorld->setSeedType(SeedType::Sunflower);
    }
}
