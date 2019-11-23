#include "carton.h"

Carton::Carton(int x, int y, int id){
    //on s'assure d'avoir un carton de taille >=1
    if(x<0) this->x = 1;
    else this->x = x;
    if(y<0) this->y = 1;
    else this->y = y;
    this->id = id;
    size = this->x*this->y;
}

QVector<Carton*> Carton::cartonFactory(int number, int bound){
    QVector<Carton*> list;
    Carton* tmp;
    for(int i = 0; i < number; i++){
        int x = QRandomGenerator::global()->bounded(1, bound);
        int y = QRandomGenerator::global()->bounded(1, bound);
        tmp = new Carton(x,y,i+1);
        list.append(tmp);
    }

    return list;
}

int Carton::getX(bool reverse){
    if(!reverse) return x;
    else return y;
}
int Carton::getY(bool reverse){
    if(!reverse) return y;
    else return x;
}

int Carton::getId(){
    return id;
}
