#ifndef POLE_VAULT_ZOMBIE_HPP__
#define POLE_VAULT_ZOMBIE_HPP__

#include "../Zombie/Zombie.hpp"

class PoleVaultZombie : public Zombie {
    public:
        void Update();
        PoleVaultZombie(int x, int y);
        int getJumpTime() const;
        void setJumpTime(int t);

    private:
        int jumpTimer;

};

#endif // !DEBUG
