#include "porte.h"

//**************************************************constructeur***********************************************
Porte::Porte():tempo1(),tempo2()
{
    coordporteg.x = 324;

    coordporteg.y = 395;

    coordported.x = 394;

    coordported.y = 395;

    portedroite = IMG_Load("ported.pcx");

    portegauche = IMG_Load("porteg.pcx");

    etat = FERMER;

    SDL_SetAlpha(portegauche, SDL_SRCALPHA, 200);

    SDL_SetAlpha(portedroite, SDL_SRCALPHA, 200);

}


//******************************procedure permettant de fixer les portes***************************************
void Porte::Fixer(SDL_Rect p)
{
    coordporteg.x = p.x;

    coordporteg.y = p.y;

    coordported.x = p.x + 70;

    coordported.y = p.y;

    Ouverture=0;

    Fermeture=0;

}

//********************************procedure ouverture d'une porte ***********************************************
void Porte::Ouvrir()
{
    if(tempo1.Chrono(1000))  {Ouverture=1;}

    if(Ouverture==1)
    {
        if(tempo1.Chrono(4))
        {
            if(coordporteg.x>262) {coordporteg.x-=1;}

            if(coordported.x<456) {coordported.x+=1;}
        }


        if(coordporteg.x==262&&coordported.x==456)
        {
            etat=OUVERT;

            Ouverture=0;
        }

    }
}

int Porte::EtatPorte()  {return etat;}


//******************************procedure permettant de fermer une porte******************************************
void Porte::Fermer()
{
    if(tempo2.Chrono(500))   {Fermeture=1;}

    if(Fermeture == 1)
    {
        if(tempo2.Chrono(1))
        {
            if(coordporteg.x<324) {coordporteg.x+=1;}

            if(coordported.x>394) {coordported.x-=1;}

        }

        if(coordporteg.x==324&&coordported.x==394)
        {
            etat=FERMER;

            Fermeture=0;
        }
    }
}


//**********************************procedure permettant d'afficher les portes*************************************
void Porte::Afficher(SDL_Surface* ecr)
{
    SDL_BlitSurface(portegauche,NULL,ecr,&coordporteg);

    SDL_BlitSurface(portedroite,NULL,ecr,&coordported);
}


//**************************************destructeur de la classe***************************************************
Porte::~Porte()
{
    SDL_FreeSurface(portedroite);

    SDL_FreeSurface(portegauche);
}
