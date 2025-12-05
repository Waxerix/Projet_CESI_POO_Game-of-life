#include "../headers/Grille.hpp"

Grille::Grille(){}

void Grille::SetX(int x){this->x=x;}

void Grille::SetY(int y){this->y=y;}

void Grille::SetGrille(std::vector<std::vector<Cellules*>> G){grille=G;}

int Grille::GetX(){return x;}

int Grille::GetY(){return y;}

bool Grille::GetEtat(int x,int y){
    if (!grille[y][x]) return false; // treat nullptr as dead cell
    return grille[y][x]->GetEtat();
}

void Grille::NewGrille(){
    std::vector<std::vector<Cellules*>> NewG(y, std::vector<Cellules*>(x, nullptr));

    for(int y=0;y<this->y;y++){
        for(int x=0;x<this->x;x++){
            if(this->grille[y][x]->GetEtat()){
                int count=0;
                int x1,y1,x2,y2;
                if(y-1<0){y1=this->GetY()-1;}
                else{y1=y-1;}
                if(y+1>=this->GetY()){y2=0;}
                else{y2=y+1;}
                if(x-1<0){x1=this->GetX()-1;}
                else{x1=x-1;}
                if(x+1>=this->GetX()){x2=0;}
                else{x2=x+1;}

                if(this->GetEtat(x1,y1)){count+=1;}
                else if(NewG[y1][x1]==nullptr){this->NewEtatMort(x1,y1,NewG);}

                if(this->GetEtat(x2,y1)){count+=1;}
                else if(NewG[y1][x2]==nullptr){this->NewEtatMort(x2,y1,NewG);}

                if(this->GetEtat(x1,y2)){count+=1;}
                else if(NewG[y2][x1]==nullptr){this->NewEtatMort(x1,y2,NewG);}

                if(this->GetEtat(x,y1)){count+=1;}
                else if(NewG[y1][x]==nullptr){this->NewEtatMort(x,y1,NewG);}

                if(this->GetEtat(x,y2)){count+=1;}
                else if(NewG[y2][x]==nullptr){this->NewEtatMort(x,y2,NewG);}

                if(this->GetEtat(x1,y)){count+=1;}
                else if(NewG[y][x1]==nullptr){this->NewEtatMort(x1,y,NewG);}

                if(this->GetEtat(x2,y)){count+=1;}
                else if(NewG[y][x2]==nullptr){this->NewEtatMort(x2,y,NewG);}

                if(this->GetEtat(x2,y2)){count+=1;}
                else if(NewG[y][x]==nullptr){this->NewEtatMort(x,y,NewG);}

                if(count<2 || count>3){NewG[y][x]=new CellulesMortes;}
                else{NewG[y][x]=new CellulesVivantes;}
            }
        }
    }

    for(int y=0;y<this->y;y++){
        for(int x=0;x<this->x;x++){
            if(NewG[y][x]==nullptr){NewG[y][x]=new CellulesMortes;}
        }
    }

    this->grille=NewG;
}
    
void Grille::NewEtatMort(int x,int y,std::vector<std::vector<Cellules*>>& NewG){
        int count=0;
        int x1,y1,x2,y2;
        if(y-1<0){y1=this->GetY()-1;}
        else{y1=y-1;}
        if(y+1>=this->GetY()){y2=0;}
        else{y2=y+1;}
        if(x-1<0){x1=this->GetX()-1;}
        else{x1=x-1;}
        if(x+1>=this->GetX()){x2=0;}
        else{x2=x+1;}


        if(this->GetEtat(x1,y1)){count+=1;}

        if(this->GetEtat(x2,y1)){count+=1;}

        if(this->GetEtat(x1,y2)){count+=1;}

        if(this->GetEtat(x,y1)){count+=1;}

        if(this->GetEtat(x,y2)){count+=1;}

        if(this->GetEtat(x1,y)){count+=1;}

        if(this->GetEtat(x2,y)){count+=1;}

        if(this->GetEtat(x2,y2)){count+=1;}

        if(count==3){NewG[y][x]=new CellulesVivantes;}
}
