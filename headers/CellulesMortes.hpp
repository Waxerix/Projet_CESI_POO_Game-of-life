#include "../headers/Cellules.hpp"

class CellulesMortes : public Cellules {
    public:
        CellulesMortes();
        bool GetEtat() const override;
        void NewEtat() const override;
};