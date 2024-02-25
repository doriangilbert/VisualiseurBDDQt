#include "MainWindow.h"

#include <QApplication>

//** Fonction principale **//
int main(int argc, char *argv[])
{
    //** Création de l'application **//
    QApplication a(argc, argv);
    //** Création de la fenêtre principale **//
    MainWindow w;
    //** Affichage de la fenêtre principale **//
    w.show();
    //** Exécution de l'application **//
    return a.exec();
}
