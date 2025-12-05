#include "../headers/Cellules.hpp"

class CellulesVivantes : public Cellules {
    public:
        CellulesVivantes();
        bool GetEtat() const override;
        void NewEtat() const override;
};