#ifndef BUCK_ZOMBIE_HPP__
#define BUCK_ZOMBIE_HPP__

#include "../Zombie/Zombie.hpp"

class BuckZombie : public Zombie {
    public:
        void Update();
        BuckZombie(int x, int y);

};

#endif // !DEBUG
