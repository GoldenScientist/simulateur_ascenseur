#include "temporisateur.h"

Temporisateur::Temporisateur():cloche()
{
    TTF_Init();

    temps1=0;

    temps2=0;

    tempscourant1=0;

    tempscourant2=0;

    etat=1;

    surfacetexte=NULL;

    surfacetemps=NULL;

    SurfacenumPersonne=NULL;

    couleurtexte = { 255, 255, 255 };

    police=TTF_OpenFont("a.ttf",20);

    time(&temps);

    instant= *localtime(&temps);

    initialise = 1;
    sous_heure = 0;
}

void Temporisateur::AfficherNbpers(SDL_Surface *ecr, SDL_Rect pc, int nbh)
{
    sprintf(numPersonne,"Numero personne: %4d",nbh);

    SurfacenumPersonne = TTF_RenderText_Blended(police,numPersonne,couleurtexte);

    SDL_BlitSurface(SurfacenumPersonne,NULL,ecr,&pc);

    SDL_FreeSurface(SurfacenumPersonne);

}

void Temporisateur::AfficherTemps(SDL_Surface *ecr, SDL_Rect p)
{
    tempscourant1=SDL_GetTicks();

    time(&temps);

    instant= *localtime(&temps);

    heure =SDL_GetTicks();

    if(initialise==1)
    {
        sous_heure = SDL_GetTicks();
        initialise = 0;
    }
    if(initialise == 0)
    {
        heure -= sous_heure;
    }

    sprintf(h,"Horloge: %2d:%2d:%2d",heure/3600/1000%24,heure/60/1000%60,heure/1000%60);

    sprintf(t,"Temps actuel: %2d:%2d:%2d",instant.tm_hour, instant.tm_min, instant.tm_sec);

    if(tempscourant1-tempscourant2>1100)
    {
        cloche.Tic();

        tempscourant2=tempscourant1;
    }

    surfacetexte = TTF_RenderText_Blended(police,t,couleurtexte);

    surfacetemps = TTF_RenderText_Blended(police,h,couleurtexte);

    p.x+=55;

    SDL_BlitSurface(surfacetexte,NULL,ecr,&p);

    p.y+=30;

    SDL_BlitSurface(surfacetemps,NULL,ecr,&p);

    SDL_FreeSurface(surfacetexte);

    SDL_FreeSurface(surfacetemps);

}

int Temporisateur::Chrono(int delai)
{
    if(etat==1)
    {
       etat=0;

       temps1=SDL_GetTicks();
    }

    if(etat==0)
    {
       temps2=SDL_GetTicks();
    }

    if(((temps2-temps1)>delai))
    {
        etat=1;

        return 1;
    }

    return 0;
}


Temporisateur::~Temporisateur()
{
    //SDL_FreeSurface(surfacetexte);

    TTF_CloseFont(police);

    TTF_Quit();
}
