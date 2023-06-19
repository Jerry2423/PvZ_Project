#include "WallnutSeed.hpp"
#include "../../GameWorld/GameWorld.hpp"

/*
changes:
line 4: image, price, cooldowntime
last line: setSeedType to the corresponding type
   */


WallnutSeed::WallnutSeed(int x, int y) : Seed(IMGID_SEED_WALLNUT, x, y, 50, 900) {}

void WallnutSeed::OnClick() {
    if (canClick() && livingWorld->GetSun() >= getPrice()) {
        livingWorld->addSun(-getPrice());
        livingWorld->addCoolDownMask(GetX(), GetY(), getCoolDownTime());
        livingWorld->setSeedType(SeedType::Wallnut);
    }
}
