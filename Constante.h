#ifndef CONSTANTE_H_INCLUDED
#define CONSTANTE_H_INCLUDED

enum StatutPorte{
    OUVERT,
    FERMER
};

enum Origine
{
    ETAGE1 = 1,
    ETAGE2
};

enum OrdreSprite
{
    DEBOUT,
    ALLERA,
    ENTREE,
    SORTIR,
    DISPARAITRE
};

enum PosSprite
{
    DEV_ASC_H = -1,//pour aller chercher l'ascenseur
    VENIR,
    DEV_ASC_B, //pour aller chercher l'ascenseur
    DANS_ASC,
    DER_ASC,
    PARTIR
};

enum Direction
{
    GAUCHE = 1,
    DROITE
};

enum CouleurPanneau
{
    ROUGE = 1,
    VERTE
};

#define ENTREEG 282

#define ENTREED 466

#define SORTIED 450

#define SORTIEG 282

#endif // CONSTANTE_H_INCLUDED
