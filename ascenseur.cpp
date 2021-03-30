#include "ascenseur.h"


//***********************************constructeur de la classe ****************************************
Ascenseur::Ascenseur():tempo1(),tempo2()
{
    ascenseur = IMG_Load("asc.png");

    coordonnees.x = 324;

    coordonnees.y = 371;

    position=0;

    origine=ETAGE1;
    AttenteDescente=0;

    AttenteMontee=0;
}


//*********************************procedure d'affichage de l'ascenseur********************************
void Ascenseur::Afficher(SDL_Surface* ecr)
{
    SDL_BlitSurface(ascenseur,NULL,ecr,&coordonnees);
}


//*********************************procedure permettant de faire monter l'ascenseur********************************
void Ascenseur::Monter()
{
    if(tempo1.Chrono(700))
    {
        AttenteMontee=1;
    }

    if(coordonnees.y>71&&AttenteMontee==1&&tempo1.Chrono(7))
    {
        coordonnees.y-=1;
    }
}


//*********************************procedure permettant de faire descendre l'ascenseur********************************
void Ascenseur::Descendre()
{
    if(tempo2.Chrono(700))
    {
        AttenteDescente=1;
    }

    if(coordonnees.y<371&&AttenteDescente==1&&tempo2.Chrono(7))
    {
        coordonnees.y+=1;
    }
}


//*********************************procedure permettant d'obtenir la position de l'ascenseur********************************
int Ascenseur::Position()
{
    if(coordonnees.y==71)
    {
        position=ETAGE2;//2

        origine=ETAGE2;//2


        AttenteMontee=0;

    }

    if(coordonnees.y==371)
    {
        position=ETAGE1;//1

        origine=ETAGE1;//1

        AttenteDescente=0;



    }
    return position;
}

int Ascenseur::Origine()
{
    return origine;
}

int Ascenseur::Hauteur()
{
    return coordonnees.y;
}


//**********************************************destructeur de la classe******************************************************
Ascenseur::~Ascenseur()
{
    SDL_FreeSurface(ascenseur);
}
