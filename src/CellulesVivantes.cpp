#include "../headers/CellulesVivantes.hpp"

CellulesVivantes::CellulesVivantes(){}

CellulesVivantes::CellulesVivantes(bool obstacle){this->obstacle=obstacle;}

bool CellulesVivantes::GetEtat() const{
    return true;
}
