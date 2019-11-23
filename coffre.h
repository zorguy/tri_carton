#ifndef COFFRE_H
#define COFFRE_H

#include "carton.h"
#include <QVector>
#include <iostream>


class Coffre
{
private:
    int x;
    int y;
    int size;
    //QVector<Carton*> poses;
    QVector<QVector<int>*> dansLeCoffre;
    bool tenterPoserCarton(Carton* c, int origineCoffreX, int origineCoffreY);
    bool poserCarton(Carton*c, bool transp, int origineCoffreX, int origineCoffreY);

public:
    Coffre(int x, int y);
    int getX();
    int getY();
    int getSize();
    void ranger(QVector<Carton*> list);

    void toString();
};

#endif // COFFRE_H
