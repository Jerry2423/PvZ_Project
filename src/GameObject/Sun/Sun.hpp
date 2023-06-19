#ifndef SUN_HPP__
#define SUN_HPP__

#include "../GameObject.hpp"
#include "../../utils.hpp"
// #include "../../GameWorld/GameWorld.hpp"

/*
   fall_time
   living world
   movement(diff) //behave diff
   bool land?
   dead->300 ticks
   landing time
   add sun pts
property:
falling_time
land?
landing_time >=300ticks -> dead!->disappear
live?/isDead()?
living world;

function:
movement
   */

class Sun : public GameObject {
    public:
        // virtual void movement() = 0;
        Sun(ImageID imageID, int x, int y, LayerID layer, AnimID animID, int falling_time);
        bool isZombie() const;
        bool isDead() const;

        bool isOnLand() const;
        int getFallingTime() const;
        int getOnLandTime() const;
    
        void decrFallingTime();
        void decrOnLandTime();
        void setFallingTime(int t);
        void setOnLandTime(int t);

        virtual ~Sun() = default;

        void OnClick();
    private:
        int falling_time;
        // bool isOnLand; //this may be same as falling_time, isOnland is true if falling_time == 0
        int onLandTime; 
        // pGameWorld livingWorld;
};


#endif // !DEBUG
