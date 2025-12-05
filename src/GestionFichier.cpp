#include "../headers/GestionFichier.hpp"
#include <fstream>

GestionFichier::GestionFichier(){}

Grille GestionFichier::GetGrille(std::string fichier) {
    std::ifstream ifs(fichier);
    if (!ifs.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << fichier << std::endl;
        return Grille(); // grille vide
    }

    int y, x;
    ifs >> y >> x;      // lire dimensions
    ifs.ignore();       // sauter le reste de la ligne

    std::vector<std::vector<Cellules*>> G(y, std::vector<Cellules*>(x, nullptr));

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            int val;
            ifs >> val;  // lire un entier séparé par des espaces
            if (val == 1)
                G[i][j] = new CellulesVivantes();
            else
                G[i][j] = new CellulesMortes();
        }
    }

    Grille grille;
    grille.SetGrille(G);
    grille.SetX(x);
    grille.SetY(y);
    return grille;
}


