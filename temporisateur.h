#ifndef TEMPORISATEUR_H_INCLUDED
#define TEMPORISATEUR_H_INCLUDED

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include "cloche.h"
#include "Constante.h"

class Temporisateur
{

    private:

            int temps1;

            int temps2;

            int etat;

            Cloche cloche;

            int tempscourant1;

            int tempscourant2;

            int heure;

            time_t temps;

            struct tm instant;

            TTF_Font *police;

            SDL_Color couleurtexte;

            SDL_Surface *surfacetexte;

            SDL_Surface *surfacetemps;

            SDL_Surface *SurfacenumPersonne;

            SDL_Surface *z_prochain;

            char t[50];

            char h[20];

            char numPersonne[20];

            int initialise;

            int sous_heure;

    public:

            Temporisateur();

            void AfficherTemps(SDL_Surface*, SDL_Rect);

            void AfficherNbpers(SDL_Surface*,SDL_Rect,int);

            int Chrono(int);

            ~Temporisateur();

};

#endif // TEMPORISATEUR_H_INCLUDED
