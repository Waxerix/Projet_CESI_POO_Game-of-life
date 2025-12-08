#include "../headers/Interface.hpp"

Interface::Interface(){}

void Interface::renderGrid(sf::RenderWindow &window,Grille G){
    int x,y;
    window.clear();
    float cellSize = 800.0f / std::max(G.GetX(),G.GetY());
    

    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

    for (int x = 0; x < G.GetX(); ++x) {
        for (int y = 0; y < G.GetY(); ++y) {
            if (G.GetEtat(x,y)) {
                cell.setPosition(sf::Vector2f(x * cellSize, y * cellSize)); // SFML 2.6+ requires Vector2f
                window.draw(cell);
            }
        }
    }
    window.display();
}

void Interface::Run(){
    int action,times=0,count=0;
    bool save;
    GestionFichier GF;
    std::string nom;
    std::cout << "Quel est le nom du fichier?" << std::endl;
    std::cin >> nom;
    Grille G=GF.GetGrille("data/"+nom+".txt");

    float cellSize = 800.0f / std::max(G.GetX(),G.GetY());
    
    std::cout << "Grille: " << G.GetX() << "x" << G.GetY() << std::endl;

    std::cout << "Voulez-vous enregistrer les n premières itérations?\n 1.oui \n 2.non" << std::endl;
    std::cin >> action;
    if (action==1){
        save=true;
        std::cout << "Combien d'itérations voulez vous enregistrer?" << std::endl;
        std::cin >> times;
    }
    else{save=false;}

    sf::Vector2u winSize(G.GetX() * cellSize, G.GetY() * cellSize);
    sf::RenderWindow window(sf::VideoMode(winSize), "Game of Life");

    while (window.isOpen()) {
        // pollEvent() now returns std::optional<Event> instead of taking a reference
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        this->renderGrid(window,G);

        sf::sleep(sf::milliseconds(50));

        G.NewGrille();

        if (save && count<times){
            count+=1;
            GF.SaveGrille(G,nom,count);
        }

    }
}