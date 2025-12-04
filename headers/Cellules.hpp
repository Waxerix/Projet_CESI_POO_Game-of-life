#include <iostream>

class Cellules {
    protected:
        int x;
        int y;
        bool obstacle;
    public:
        Cellules();
        bool GetEtat();
        void NewEtat();
        bool Obstacle();
};