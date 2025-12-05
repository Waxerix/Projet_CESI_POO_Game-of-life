#pragma once
#include <iostream>

class Cellules {
    protected:
        int x;
        int y;
        bool obstacle;
    public:
        Cellules();
        virtual bool GetEtat() const = 0;
        virtual void NewEtat() const = 0;
        bool Obstacle();
};