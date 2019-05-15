/**
  *@file adresseipv4.cpp
  * @brief Définition de la classe Main
  * @version 1.8
  * @date   14 mai 2019
  * @author Alex et Sofiane
  * @details Ceci est une calculatrice IPV4, cela calcule les adresses ipv4 et ouais!
  */

#include "calculatriceip.h"
#include <QApplication>
/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatriceIP w;
    w.show();

    return a.exec();
}
