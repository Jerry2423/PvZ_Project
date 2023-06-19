#ifndef REG_ZOMBIE_HPP__
#define REG_ZOMBIE_HPP__

#include "../Zombie/Zombie.hpp"

class RegZombie : public Zombie {
    public:
        void Update();
        RegZombie(int x, int y);

};

#endif // !DEBUG
