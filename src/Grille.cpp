#include "../headers/Grille.hpp"

Grille::Grille(){}

void Grille::SetX(int x){this->x=x;}

void Grille::SetY(int y){this->y=y;}

void Grille::SetGrille(std::vector<std::vector<Cellules*>> G){this->grille=G;}

int Grille::GetX(){return this->x;}

int Grille::GetY(){return this->y;}

bool Grille::GetEtat(int x,int y){return this->grille[y][x]->GetEtat();}

