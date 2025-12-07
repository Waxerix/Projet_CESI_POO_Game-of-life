#include "../headers/Cellules.hpp"

class CellulesVivantes : public Cellules {
    public:
        CellulesVivantes();
        CellulesVivantes(bool obstacle);
        bool GetEtat() const override;
};