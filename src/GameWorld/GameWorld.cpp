#include "GameWorld.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include "../GameObject/GameObject.hpp"
#include "../GameObject/Background/Background.hpp"
#include "../GameObject/FlowerSun/FlowerSun.hpp"
#include "../GameObject/SkySun/SkySun.hpp"
#include "../GameObject/PlantingSpot/PlantingSpot.hpp"
#include "../GameObject/CooldownMask/CooldownMask.hpp"
#include "../GameObject/SunFlowerSeed/SunFlowerSeed.hpp"
#include "../GameObject/SunFlower/SunFlower.hpp"
#include "../GameObject/Shovel/Shovel.hpp"
#include "../GameObject/PeashooterSeed/PeashooterSeed.hpp"
#include "../GameObject/Pea/Pea.hpp"
#include "../GameObject/Peashooter/Peashooter.hpp"
#include "../GameObject/RegZombie/RegZombie.hpp"
#include "../GameObject/WallnutSeed/WallnutSeed.hpp"
#include "../GameObject/Wallnut/Wallnut.hpp"
#include "../GameObject/CherrySeed/CherrySeed.hpp"
#include "../GameObject/Cherry/Cherry.hpp"
#include "../GameObject/Explosion/Explosion.hpp"
#include "../GameObject/RepeaterSeed/RepeaterSeed.hpp"
#include "../GameObject/Repeater/Repeater.hpp"
#include "../GameObject/BuckZombie/BuckZombie.hpp"
#include "../GameObject/PoleVaultZombie/PoleVaultZombie.hpp"

using std::cout; using std::endl;

GameWorld::GameWorld()  : zombieInterval(1200), timer(0), sunInterval(300), bunnyMarker(SeedType::Default) {}

GameWorld::~GameWorld() {}


SeedType GameWorld::getSeedType() const {
    switch (bunnyMarker) {
        case SeedType::Sunflower:
            return SeedType::Sunflower;
        case SeedType::Peashooter:
            return SeedType::Peashooter;
        case SeedType::Wallnut:
            return SeedType::Wallnut;
        case SeedType::Repeater:
            return SeedType::Repeater;
        case SeedType::Cherry:
                return SeedType::Cherry; 
        case SeedType::Shovel:
            return SeedType::Shovel;
        default:
            return SeedType::Default;
    }
}

void GameWorld::setSeedType(SeedType seed) {
    bunnyMarker = seed;
}

void GameWorld::genSun(SunType sun, int x, int y) {
    switch (sun) {
        case SunType::FlySun:
            objects.push_back(std::make_shared<SkySun>(x, y));
            break;
        default:
            objects.push_back(std::make_shared<FlowerSun>(x, y));
            break;
    }
}

void GameWorld::addObject(SeedType seed, int x, int y) {
    switch (seed) {
        case SeedType::Sunflower:
            objects.push_back(std::make_shared<SunFlower>(x, y));
            break;
        case SeedType::Peashooter:
            objects.push_back(std::make_shared<Peashooter>(x, y));
            break;
        case SeedType::Wallnut:
            objects.push_back(std::make_shared<Wallnut>(x, y));
            break;
        case SeedType::Repeater:
            objects.push_back(std::make_shared<Repeater>(x, y));
            break;
        case SeedType::Cherry:
            objects.push_back(std::make_shared<Cherry>(x, y));
            break;
        default:
            break;
    }
}

void GameWorld::addCoolDownMask(int x, int y, int coolDownTime) {
    auto temp = std::make_shared<CooldownMask>(x, y, coolDownTime);
    objects.push_back(temp);
}

void GameWorld::addPea(int x, int y) {
    objects.push_back(std::make_shared<Pea>(x, y));
}

void GameWorld::addExplosion(int x, int y) {
    objects.push_back(std::make_shared<Explosion>(x, y));
}

bool GameWorld::findZombie(int x, int y) const {
    auto getZombie = [x, y](std::shared_ptr<GameObject> i) {
        return i->GetX() >= x && i->GetY() == y && i->isZombie(); 
    };
    // cout << "target position at" << x <<  " " << y << endl;
    return !(std::find_if(objects.begin(), objects.end(), getZombie) == objects.end());    
}

int GameWorld::getTime() const {
    return timer;
}

void GameWorld::setTimer(int t) {
    timer = t;
}

int GameWorld::getSunInterval() const {
    return sunInterval;
}

void GameWorld::setSunInterval(int t) {
    sunInterval = t;
}

int GameWorld::getZInterval() const {
    return zombieInterval;
}

void GameWorld::setZInterval(int t) {
    zombieInterval = t;
}

void GameWorld::addSun(int num) {
    SetSun(GetSun()+num);
}

bool GameWorld::SameType(std::shared_ptr<GameObject> p1, std::shared_ptr<GameObject> p2) const {
    return (p1->isZombie() && p2->isZombie()) || (!p1->isZombie() && !p2->isZombie());
}

bool GameWorld::inRange(int a, int b, int c) const {
    return c >= a && c <= b;
}

bool GameWorld::CollisionDetect(std::shared_ptr<GameObject> p1, std::shared_ptr<GameObject> p2) const {
    if (SameType(p1, p2)) {
        return false;
    }
    int l1_x = p1->GetX() - p1->GetWidth() / 2;
    int l1_y = p1->GetY() + p1->GetHeight() / 2;
    int r1_x = p1->GetX() + p1->GetWidth() / 2;
    int r1_y = p1->GetY() - p1->GetHeight() / 2;

    int l2_x = p2->GetX() - p2->GetWidth() / 2;
    int l2_y = p2->GetY() + p2->GetHeight() / 2;
    int r2_x = p2->GetX() + p2->GetWidth() / 2;
    int r2_y = p2->GetY() - p2->GetHeight() / 2;

    if (r1_x < l2_x || r2_x < l1_x) {
        return false;
    }
    if (r1_y > l2_y || r2_y > l1_y) {
        return false;
    }
    return true;

}

bool GameWorld::collWithPlant(std::shared_ptr<GameObject> p) const {
    if (!p->isZombie()) {
        return false;
    }
    for (auto i : objects) {
        if (i->isPlant() && !i->isAttacker() && CollisionDetect(i, p)) {
            return true;
        }
    }
    return false;
}


void GameWorld::Init() {
    // YOUR CODE HERE
    GameObject::setWorld(shared_from_this());
    shared_from_this()->SetWave(0);
    shared_from_this()->SetSun(50);
    // std::shared_ptr<Background> backPtr(new Background(IMGID_BACKGROUND, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION)); 
    auto backPtr = std::make_shared<Background>(IMGID_BACKGROUND, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION);     
    shared_from_this()->objects.push_back(backPtr);
    timer = 0;
    bunnyMarker = SeedType::Default;
    sunInterval = 300;
    zombieInterval = 1200;


    // planting spot
    for (int x = 0; x < GAME_COLS; x++) {
        for (int y = 0; y < GAME_ROWS; y++) {
            auto temp = std::make_shared<PlantingSpot>(FIRST_COL_CENTER + x*LAWN_GRID_WIDTH, FIRST_ROW_CENTER + y*LAWN_GRID_HEIGHT);
            objects.push_back(temp);
            // cout << "init at" <<  FIRST_COL_CENTER + x*LAWN_GRID_WIDTH << " " << FIRST_ROW_CENTER + y*LAWN_GRID_HEIGHT << endl;
        }
    }

    //seed buttons
    auto sunflowerButton = std::make_shared<SunFlowerSeed>(130, WINDOW_HEIGHT-44);
    objects.push_back(sunflowerButton);
    //Peashooter button
    objects.push_back(std::make_shared<PeashooterSeed>(130+60, WINDOW_HEIGHT-44));
    //WallnutSeed button
    objects.push_back(std::make_shared<WallnutSeed>(130+60*2, WINDOW_HEIGHT-44));
    //Cheery button
    objects.push_back(std::make_shared<CherrySeed>(130+60*3, WINDOW_HEIGHT-44));
    //Repeater button
    objects.push_back(std::make_shared<RepeaterSeed>(130+60*4, WINDOW_HEIGHT-44));


    //shovel button
    objects.push_back(std::make_shared<Shovel>(600, WINDOW_HEIGHT-40));
}

LevelStatus GameWorld::Update() {
    // YOUR CODE HERE: MIND THE ORDER!
    
    //generate sun
    if (getTime() == 180 || getSunInterval() == 0) {
        auto temp = std::make_shared<SkySun>(randInt(75, WINDOW_WIDTH-75), WINDOW_HEIGHT-1);
        objects.push_back(temp);
        setSunInterval(300);
        // SetSun(GetSun()+25);
    }
    setTimer(getTime()+1);
    setSunInterval(getSunInterval()-1);
    
    //generate zombie
    if (getZInterval() == 0) {
        int numZ = (15+GetWave()) / 10;
        setZInterval(std::max(150, 600 - 20 * GetWave()));
        SetWave(GetWave()+1);
        std::vector<int> yCord;
        for (int i = 0; i < 5; i++) {
            yCord.push_back(FIRST_ROW_CENTER + i * LAWN_GRID_HEIGHT);
        }
        
        for (int i = 0; i < numZ; i++) {
            int p1 = 20;
            int p2 = 2 * std::max(GetWave()-8, 0);
            int p3 = 3 * std::max(GetWave()-15, 0);
            int prob = randInt(0, p1+p2+p3);
            // cout << p1 << " " << p2 << " " << " " << p3 <<" " << prob << endl;
            if (prob <= p1) {
                objects.push_back(std::make_shared<RegZombie>(randInt(WINDOW_WIDTH-40, WINDOW_WIDTH-1), yCord[randInt(0, 4)]));
                // cout << "reg" << endl;
            } else if (prob <= p1+p2) {
                objects.push_back(std::make_shared<PoleVaultZombie>(randInt(WINDOW_WIDTH-40, WINDOW_WIDTH-1), yCord[randInt(0, 4)]));
                // cout << "jump" << endl;
            } else {
                objects.push_back(std::make_shared<BuckZombie>(randInt(WINDOW_WIDTH-40, WINDOW_WIDTH-1), yCord[randInt(0, 4)]));
                // cout << "buck" << endl;
            }
        }
    } else {
        setZInterval(getZInterval()-1);
    }
    
    //Update
    for (auto i : objects) {
        i->Update();
    }


    //collision detection
    for (auto i : objects) {
        if (i->isZombie()) {
            for (auto j : objects) {
                if (j->isPlant() && CollisionDetect(j, i)) {
                    if (!j->isAttacker())
                        i->collide();
                    j->setHP((j->getHP()) - (i->getAttVal()));
                    i->setHP((i->getHP()) - (j->getAttVal()));
                    // if (!j->isAttacker())
                } 
            }
        }
    }


    
    

    //recheck coolision
    for (auto i : objects) {
        if (i->isZombie()) {
            for (auto j : objects) {
                if (j->isPlant() && !j->isAttacker() && CollisionDetect(j, i) && i->getMState() == MotionState::Stop &&j->isDead()) {
                    i->setMState(MotionState::Move); 
                    i->PlayAnimation(ANIMID_WALK_ANIM);
                }
            }
        }
    }
    //remove dead
    auto checkDead = [](std::shared_ptr<GameObject> i) {
        return i->isDead();
    };
    objects.remove_if(checkDead);    

    //check lose
    for (auto i : objects) {
        if (i->isZombie() && i->GetX() < 0)
            return LevelStatus::LOSING;
    }
    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // YOUR CODE HERE
    objects.clear();
}

