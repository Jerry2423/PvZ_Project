#include "CherrySeed.hpp"
#include "../../GameWorld/GameWorld.hpp"
#define PRICE 150
#define COOLDOWN_TIME 1200 
/*
changes:
line 4: image, price, cooldowntime
last line: setSeedType to the corresponding type
   */


CherrySeed::CherrySeed(int x, int y) : Seed(IMGID_SEED_CHERRY_BOMB, x, y, PRICE, COOLDOWN_TIME) {}

void CherrySeed::OnClick() {
    if (canClick() && livingWorld->GetSun() >= getPrice()) {
        livingWorld->addSun(-getPrice());
        livingWorld->addCoolDownMask(GetX(), GetY(), getCoolDownTime());
        livingWorld->setSeedType(SeedType::Cherry);
    }
}
