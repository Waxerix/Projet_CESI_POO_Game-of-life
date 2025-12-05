#include "../headers/Interface.hpp"

Interface::Interface(){}

void Interface::renderGrid(sf::RenderWindow &window,Grille G){
    int x,y;
    window.clear();
    int cellSize = 10;
    

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
    int cellSize = 10;
    GestionFichier GF;
    std::string nom="data/test.txt";
    Grille G=GF.GetGrille(nom);
    
    std::cout << "Grille: " << G.GetX() << "x" << G.GetY() << std::endl;
    sf::Vector2u winSize(G.GetX() * cellSize, G.GetY() * cellSize);
    sf::RenderWindow window(sf::VideoMode(winSize), "Game of Life");

    while (window.isOpen()) {
        // pollEvent() now returns std::optional<Event> instead of taking a reference
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        renderGrid(window,G);

        sf::sleep(sf::milliseconds(100));
    }
}