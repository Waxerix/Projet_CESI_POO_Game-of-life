#include "../headers/CellulesVivantes.hpp"
#include "../headers/CellulesMortes.hpp"
#include <iostream>

class Grille{
private:
    std::vector<std::vector<Cellules*>> grille;
    int x;
    int y;
public:
    Grille();
    void NewGrille();
    void SetX(int x);
    void SetY(int y);
    void SetGrille(std::vector<std::vector<Cellules*>> G);
    void NewEtatMort(int x,int y,std::vector<std::vector<Cellules*>>& NewG);
    int GetX();
    int GetY();
    bool GetEtat(int x,int y);
};