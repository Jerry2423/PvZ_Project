#ifndef COOLDOWN_MASK_HPP__
#define COOLDOWN_MASK_HPP__

#include "../GameObject.hpp"

class CooldownMask: public GameObject {
    public:

        CooldownMask(int x, int y, int cooldownTime);

        void Update();
        void OnClick();
        bool isDead() const;
        bool isZombie() const;

        int getTime() const;
        void setTimer(int t);

    private:
        int timer;
};

#endif // !DEBUG
