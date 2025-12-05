#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../headers/GestionFichier.hpp"

class Interface{
public:
    Interface();
    void Run();
    void renderGrid(sf::RenderWindow &window,Grille G);
};