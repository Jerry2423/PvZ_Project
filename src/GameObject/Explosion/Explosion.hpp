#ifndef EXPLOSION_HPP__
#define EXPLOSION_HPP__
// #include "../GameObject.hpp"
#include "../Attacker/Attacker.hpp"

class Explosion : public Attacker {
    public:
        Explosion(int x, int y);
        void Update();
        // void OnClick();
        // bool isPlant() const;
        // bool isAttacker() const;

        int getTime() const;
        void setTime(int t);

    private:
        int timer;
};

#endif // !DEBUG
