#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "QVector"
#include "carton.h"
#include "coffre.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);

    //création de @param1 cartons de taille allant de 1 à @param2
    QVector<Carton*> list = Carton::cartonFactory(9, 5);
    //création d'un coffre de taille @param1 * @param2
    Coffre coffre(10,10);

    //description de la liste de cartons
    for (int i = 0; i < list.length(); i++){
        std::cout << "Carton " << list.at(i)->getId() << " x=" << list.at(i)->getX(false) << " y=" << list.at(i)->getY(false) << std::endl;
    }

    //description du coffre
    std::cout << std::endl << "Coffre de taille " << coffre.getX() << "*" << coffre.getY() << " soit aire de " << coffre.getSize() << std::endl << std::endl;

    //dessin du coffre vide
    coffre.toString();
    std::cout << "Debut rangement" << std::endl;
    coffre.ranger(list);
    std::cout << "Fin rangement" << std::endl;
    coffre.toString();


    return 0;
    //MainWindow w;
    //w.show();
    //return a.exec();
}
