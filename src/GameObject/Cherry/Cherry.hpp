#ifndef CHERRY_HPP__
#define CHERRY_HPP__

#include "../Plant/Plant.hpp"

class Cherry : public Plant {
    public:
        Cherry(int x, int y);
        void Update();
        
        int getTime() const;
        void setTime(int t);

    private:
        int timer;

};

#endif // !DEBUG

/*
   timer
   interval
   signFirst?
   */
