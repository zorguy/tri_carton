#include "coffre.h"

Coffre::Coffre(int x, int y)
{
    if(x==0) this->x=1;
    else this->x = x;

    if(y==0) this->y=1;
    else this->y = y;

    size = this->x*this->y;

    for(int i = 0 ; i < this->x ; i++){
        dansLeCoffre.append(new QVector<int>);
        for(int j = 0 ; j < this->y ; j++){
            dansLeCoffre.at(i)->append(0);
        }
    }
}

int Coffre::getX(){
    return x;
}

int Coffre::getY(){
    return y;
}

int Coffre::getSize(){
    return size;
}

void Coffre::ranger(QVector<Carton*> list){
    //pour chaque carton dans la liste
    //on balaye le coffre en x et en y
    //pour chaque pixel, on check si le carton peut rentrer (fonction tenterPoserCarton partie 1)
    //s'il peut pas rentrer, on check si la transposée du carton peut rentrer (fonction tenterPoserCarton partie 2)
    //si on arrive à la fin sans pouvoir le poser, il est juste impossible de le poser et un message d'erreur apparait
    bool cartonOk;
    for(int i=0; i<list.length();i++){
        cartonOk = false;
        std::cout << "Carton " << list.at(i)->getId() << " x=" << list.at(i)->getX(false) << " y=" << list.at(i)->getY(false) << std::endl;
        for(int j = 0 ; j < this->x ; j++){
            for(int k = 0 ; k < this->y ; k++){
                if(dansLeCoffre.at(j)->at(k) == 0 && !cartonOk){
                    cartonOk = tenterPoserCarton(list.at(i), j, k);
                }
            }
        }
        std::cout << std::endl;
        toString();
        std::cout << std::endl;
        if(!cartonOk) {
            std::cout << "Impossible de ranger le carton " << list.at(i)->getId() << std::endl;
            break;
        }
    }
}

bool Coffre::tenterPoserCarton(Carton* c, int origineCoffreX, int origineCoffreY){
    //cette fonction est encore factorisable, mais au moins elle marche comme ça (le mieux est l'ennemi du bien)
    //et comme on dit, d'abord on fait en sorte que ça marche, après on fait en sorte que ça soit beau
    //et enfin on fait en sorte que ce soit opti
    bool pose = false;
    bool reverse = false;
    if(poserCarton(c, reverse, origineCoffreX, origineCoffreY)){
        for(int i = origineCoffreX; i<(origineCoffreX+c->getX(reverse)); i++){
            for(int j = origineCoffreY; j<(origineCoffreY+c->getY(reverse)); j++){
                dansLeCoffre.at(i)->replace(j, c->getId());
            }
        }
        pose=true;
    }
    else{
        reverse = !reverse;
        if(poserCarton(c, reverse, origineCoffreX, origineCoffreY)){
            for(int i = origineCoffreX; i<(origineCoffreX+c->getX(reverse)); i++){
                for(int j = origineCoffreY; j<(origineCoffreY+c->getY(reverse)); j++){
                    dansLeCoffre.at(i)->replace(j, c->getId());
                }
            }
            pose=true;
        }
    }

    return pose;
}

bool Coffre::poserCarton(Carton *c, bool transp, int origineCoffreX, int origineCoffreY){
    bool posable = true;
    if(c->getX(transp)+origineCoffreX <= getX()){
        if(c->getY(transp)+origineCoffreY <= getY()){
            for(int i = origineCoffreX; i<(origineCoffreX+c->getX(transp)); i++){
                for(int j = origineCoffreY; j<(origineCoffreY+c->getY(transp)); j++){
                    if(dansLeCoffre.at(i)->at(j) != 0) posable = false;
                }
            }
        }
        else posable = false;
    }
    else posable = false;

    return posable;
}

void Coffre::toString(){
    for(int i = 0 ; i < this->x ; i++){
        for(int j = 0 ; j < this->y ; j++){
            std::cout << dansLeCoffre.at(i)->at(j);
        }
        std::cout << std::endl;
    }
}
