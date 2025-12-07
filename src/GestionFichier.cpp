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
            if (val == 1){G[i][j] = new CellulesVivantes(false);}
            else if(val == 0){G[i][j] = new CellulesMortes(false);}
            else if (val == 3){G[i][j] = new CellulesVivantes(true);}
            else if(val == 2){G[i][j] = new CellulesMortes(true);}
        }
    }

    Grille grille;
    grille.SetGrille(G);
    grille.SetX(x);
    grille.SetY(y);
    return grille;
}

void GestionFichier::SaveGrille(Grille &G,std::string fichier,int iteration){
    std::string nomFichier=fichier+"_out"+"/"+std::to_string(iteration)+".txt";

    std::ofstream ofs (nomFichier, std::ofstream::out);

    ofs << ""<<G.GetY()<<" "<<G.GetX()<<"\n";

    for (int y=0;y<G.GetY();y++){
        for (int x=0;x<G.GetX();x++){
            if (G.GetEtat(x,y)){
                if (G.GetObstacle(x,y)){
                    ofs << "3 ";
                }
                else {ofs << "1 ";}
            }
            else {
                if (G.GetObstacle(x,y)){
                    ofs <<"2 ";
                }
                else {ofs << "0 ";}
            }
        }
        ofs <<"\n";
    }

    ofs.close();
}