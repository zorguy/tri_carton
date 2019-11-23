#ifndef CARTON_H
#define CARTON_H

#include "QRandomGenerator"
#include "QVector"


//classe carton
//représente un carton à poser, en 2D
//origine du carton en haut à gauche
//x va vers le bas, y vers la droite (standard image)
class Carton
{

private:
    //id du carton. remplaçable par tout autre chose.
    //tant que t'es en dessin asci je te déconseille d'en mettre plus de 9
    int id;
    int x;
    int y;
    int size; //size = x*y
    //constructeur en privé, pattern factory si tu connais pas
    Carton(int x, int y, int id);

public:
    //pattern factory
    static QVector<Carton*> cartonFactory(int number, int bound);
    //getX et getY prennent en param un bool
    //il sert à obtenir la transposée de la matrice
    //true = transposée, false = pas transposée
    int getX(bool reverse);
    int getY(bool reverse);
    int getId();
};

#endif // CARTON_H
