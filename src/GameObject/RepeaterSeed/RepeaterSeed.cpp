#include "RepeaterSeed.hpp"
#include "../../GameWorld/GameWorld.hpp"
#define PRICE 200
#define COOLDOWN_TIME 240 
/*
changes:
line 4: image, price, cooldowntime
last line: setSeedType to the corresponding type
   */


RepeaterSeed::RepeaterSeed(int x, int y) : Seed(IMGID_SEED_REPEATER, x, y, PRICE, COOLDOWN_TIME) {}

void RepeaterSeed::OnClick() {
    if (canClick() && livingWorld->GetSun() >= getPrice()) {
        livingWorld->addSun(-getPrice());
        livingWorld->addCoolDownMask(GetX(), GetY(), getCoolDownTime());
        livingWorld->setSeedType(SeedType::Repeater);
    }
}
