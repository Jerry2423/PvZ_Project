#ifndef PEA_HPP__
#define PEA_HPP__
#include "../Attacker/Attacker.hpp"

class Pea : public Attacker {
    public:
        Pea(int x, int y);
        void Update();
        // void OnClick();
        // bool isPlant() const;
        // bool isAttacker() const;
};

#endif // !DEBUG
