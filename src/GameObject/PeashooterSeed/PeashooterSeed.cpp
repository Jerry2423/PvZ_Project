#include "PeashooterSeed.hpp"
#include "../../GameWorld/GameWorld.hpp"

/*
changes:
line 4: image, price, cooldowntime
last line: setSeedType to the corresponding type
   */


PeashooterSeed::PeashooterSeed(int x, int y) : Seed(IMGID_SEED_PEASHOOTER, x, y, 100, 240) {}

void PeashooterSeed::OnClick() {
    if (canClick() && livingWorld->GetSun() >= getPrice()) {
        livingWorld->addSun(-getPrice());
        livingWorld->addCoolDownMask(GetX(), GetY(), getCoolDownTime());
        livingWorld->setSeedType(SeedType::Peashooter);
    }
}
