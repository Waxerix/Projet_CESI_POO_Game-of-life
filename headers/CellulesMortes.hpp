#include "../headers/Cellules.hpp"

class CellulesMortes : public Cellules {
    public:
        CellulesMortes();
        CellulesMortes(bool obstacle);
        bool GetEtat() const override;
};