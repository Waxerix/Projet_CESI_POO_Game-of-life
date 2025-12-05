#include "../headers/Grille.hpp"
#include <iostream>

class GestionFichier{
private:
    std::string name;
public:
    GestionFichier();
    Grille GetGrille(std::string fichier);
};