#ifndef REPEATER_HPP__
#define REPEATER_HPP__

#include "../Peashooter/Peashooter.hpp"

class Repeater : public Peashooter {
    public:
        Repeater(int x, int y);
        void Update();

        bool inAttM() const;
        void negAttM();

    private:
        bool attackMode;
};

#endif // !DEBUG
