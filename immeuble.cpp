#include "immeuble.h"


//*************************************le constructeur de la classe Immeuble**************************************************
Immeuble::Immeuble(SDL_Surface* ec,int NbNiv): cloche(), ascenseur(),porte1(),porte2(),led1(ec),led2(ec),temps()
{
    ecran = ec;

    mur = IMG_Load("mur.pcx");

    positiontemps.x=530;

    positiontemps.y=10;

    NombreNiveau = NbNiv;

    positionled1.x=mur->w/2-25;

    positionled2.x=mur->w/2-25;

    positionled1.y=320;

    positionled2.y=20;

    coordbarre.x=0;

    coordbarre.y=295;

    positionporte1.x = 324;

    positionporte1.y = 371;

    positionporte2.x = 324;

    positionporte2.y = 71;

    coordonnees.x = 0;

    coordonnees.y = 300;

    barre = IMG_Load("barre.png");

    porte1.Fixer(positionporte1);

    porte2.Fixer(positionporte2);

    numcouleur= VERTE;

    SDL_SetColorKey(mur, SDL_SRCCOLORKEY, SDL_MapRGB(mur->format, 255, 0, 0));

}

void Immeuble::SonnerCloche()
{
    cloche.SonnerCloche();
}

int Immeuble::OrigineAscenseur()
{
    return ascenseur.Origine();
}


//******************************************************************************************************************************

void Immeuble::AfficherHeure()
{
    temps.AfficherTemps(ecran,positiontemps);
}

//********************************procedure permettant d'afficher l'immeuble sur l'ecran*****************************************
void Immeuble::Afficher()
{
     if(NombreNiveau>1)
    {
        SDL_FillRect(ecran,0,0);

        ascenseur.Afficher(ecran);

        porte1.Afficher(ecran);

        porte2.Afficher(ecran);

        coordonnees.y = 300;

        SDL_BlitSurface(mur,NULL,ecran,&coordonnees);

        coordonnees.y = 0;

        SDL_BlitSurface(mur,NULL,ecran,&coordonnees);


        SDL_BlitSurface(barre,NULL,ecran,&coordbarre);

        led1.Allumer(positionled1,numcouleur,ascenseur.Origine());

        led2.Allumer(positionled2,numcouleur,ascenseur.Origine());

    }
    else

    {
        SDL_FillRect(ecran,0,0);

        ascenseur.Afficher(ecran);

        porte1.Afficher(ecran);

        SDL_BlitSurface(mur,NULL,ecran,&coordonnees);

        led1.Allumer(positionled1,numcouleur,ascenseur.Origine());

        temps.AfficherTemps(ecran,positiontemps);
    }
}

//********************************procedure permettant d'afficher l'immeuble sur l'ecran*****************************************
void Immeuble::Afficher(Personne& pers)
{
     if(NombreNiveau>1)
    {
        SDL_FillRect(ecran,0,0);

        ascenseur.Afficher(ecran);

        pers.Afficher(ecran);

        porte1.Afficher(ecran);

        porte2.Afficher(ecran);

        coordonnees.y = 300;

        SDL_BlitSurface(mur,NULL,ecran,&coordonnees);

        coordonnees.y = 0;

        SDL_BlitSurface(mur,NULL,ecran,&coordonnees);

        SDL_BlitSurface(barre,NULL,ecran,&coordbarre);

        led1.Allumer(positionled1,numcouleur,ascenseur.Origine());

        led2.Allumer(positionled2,numcouleur,ascenseur.Origine());


    }
    else

    {
        ascenseur.Afficher(ecran);

        porte1.Afficher(ecran);

        SDL_BlitSurface(mur,NULL,ecran,&coordonnees);

        led1.Allumer(positionled1,numcouleur,ascenseur.Origine());

        temps.AfficherTemps(ecran,positiontemps);
    }
}


//************************************faire marcher une personne dans l'immeuble****************************************************



//************************************procedure permettant d'ouvrir une porte d'ascenseurenseur de l'immeuble***********************************
void Immeuble::OuvrirPorte(int indiceporte)
{
    if(indiceporte==ETAGE1)//1
    {
        porte1.Ouvrir();
    }

    if(indiceporte==ETAGE2)//2
    {
        porte2.Ouvrir();
    }

}

//*******************************procedure permettant d'appeler l'ascenseur a un niveau**************************************************
void Immeuble::MonterAscenseur()
{
        ascenseur.Monter();
}

void Immeuble::DescendreAscenseur()
{
        ascenseur.Descendre();
}

void Immeuble::AllumerLed(int num)
{
    numcouleur = num;

}


//*************************************procedure de fermeture de la porte d'un ascenseur************************************************
void Immeuble::FermerPorte(int indiceporte)
{
    if(indiceporte==ETAGE1)   {porte1.Fermer();}//1

    if(indiceporte==ETAGE2)  {porte2.Fermer();}//2

}

int Immeuble::EtatPorte(int et)
{
    if(et==ETAGE1)  {return porte1.EtatPorte();}//1

    if(et==ETAGE2) {return porte2.EtatPorte();}//2

    return 0;
}

int Immeuble::PositionAscenseur()   {return ascenseur.Position();}

int Immeuble::HauteurAscenseur()   {return ascenseur.Hauteur();}

//****************************************destructeur de la classe*********************************************************************
Immeuble::~Immeuble()
{
    SDL_FreeSurface(mur);

    SDL_FreeSurface(ecran);

    SDL_FreeSurface(barre);

}
