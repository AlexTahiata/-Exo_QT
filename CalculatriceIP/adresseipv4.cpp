/**
  *@file adresseipv4.cpp
  * @brief Définition de la classe AdresseIPV4
  * @version 1.8
  * @date   14 mai 2019
  * @author Alex et Sofiane
  * @details Ceci est une calculatrice IPV4, cela calcule les adresses ipv4 et ouais!
  */

 #include "adresseipv4.h"

/**
 * @brief AdresseIPv4::AdresseIPv4
 * @details Cette fonction génère une adresse.
 * @param _adresse
 * @param _suffixe
 */
AdresseIPv4::AdresseIPv4(quint8 _adresse[], quint8 _suffixe)
{
    suffixe = _suffixe;
    for(int n=0; n<4; n++)
    {
        adresse[n] = _adresse[n];
    }

    CalculerMasque();

}

/**
 * @brief AdresseIPv4::ObtenirAdresseReseau
 * @details Cette fonction permet d'obtenir l'adresse réseau.
 * @param _adresseReseau
 */
void AdresseIPv4::ObtenirAdresseReseau(quint8 _adresseReseau[])
{
    for(int n=0; n<4; n++)
    {
        _adresseReseau[n] = adresse[n] & masque[n];
    }
}
/**
 * @brief AdresseIPv4::ObtenirPremierAdresse
 * @details Cette fonction permet d'obtenir la première adresse.
 * @param _premiereAdresse
 */
void AdresseIPv4::ObtenirPremierAdresse(quint8 _premiereAdresse[])
{
    for(int n=0; n <3 ; n++)
    {
        _premiereAdresse[n] = adresse[n] & masque[n];
    }
    _premiereAdresse[3] = (adresse[3] & masque[3])+1;
}

/**
 * @brief AdresseIPv4::ObtenirDerniereAdresse
 * @details Fonction qui obtiens la dernière adresse.
 * @param _derniereAdresse
 */
void AdresseIPv4::ObtenirDerniereAdresse(quint8 _derniereAdresse[])
{
    for(int n=0; n<3; n++)
    {
        _derniereAdresse[n] = adresse[n] | ~masque[n];
    }
    _derniereAdresse[3] =(adresse[3] | ~masque[3])-1;
}

/**
 * @brief AdresseIPv4::ObtenirAdresseDiffusion
 * @details Cette fonction permet d'obtenir l'adresse de diffusion
 * @param _adresseDiffusion
 */
void AdresseIPv4::ObtenirAdresseDiffusion(quint8 _adresseDiffusion[])
{
    for(int n=0 ; n<4 ; n++)
    {
        _adresseDiffusion[n] = adresse[n] | ~masque[n];
    }
}

/**
 * @brief AdresseIPv4::CalculerMasque
 * @details Fonction qui calcule le masque de sous-réseau.
 */
void AdresseIPv4::CalculerMasque()
{
    int n;
    masque[0]=0;
    masque[1]=0;
    masque[2]=0;
    masque[3]=0;

    for(n=0; n<suffixe; n++)
    {
        masque[n/8] += static_cast<quint8>  (qPow(2,(7-(n %8))));
    }
}


