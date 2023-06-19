#ifndef PEASHOOTER_HPP__
#define PEASHOOTER_HPP__

#include "../Plant/Plant.hpp"

class Peashooter : public Plant {
    public:
        Peashooter(int x, int y);
        void shoot();
        virtual void Update();
        
        int getShootInterval() const;
        void setShootInterval(int interval);

    private:
        int shootInterval;

};

#endif // !DEBUG

/*
   timer
   interval
   signFirst?
   */
