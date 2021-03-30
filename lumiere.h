#ifndef LUMIERE_H_INCLUDED
#define LUMIERE_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "temporisateur.h"
#include "Constante.h"
#include <iostream>

using namespace std;

class Lumiere
{
    private:

            SDL_Surface* ecran;

            SDL_Surface* ledvert;

            SDL_Surface* ledrouge;

            SDL_Surface* panneau;

            SDL_Color couleurPaneau;

            TTF_Font *policePaneau;

            Temporisateur tempo1;

            Temporisateur tempo2;

            string niveau;

            int activer;

        public:
                Lumiere(SDL_Surface*);

                void Allumer(SDL_Rect, int, int);

                ~Lumiere();

};


#endif // LUMIERE_H_INCLUDED
