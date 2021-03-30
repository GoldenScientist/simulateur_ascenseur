#ifndef PORTE_H_INCLUDED
#define PORTE_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "temporisateur.h"
#include "Constante.h"

class Porte
{
    private:

            SDL_Surface* portegauche;

            SDL_Surface* portedroite;

            SDL_Rect coordported;

            SDL_Rect coordporteg;

            Temporisateur tempo1;

            Temporisateur tempo2;

            int Ouverture;

            int Fermeture;

            int etat;

    public:

            Porte();

            void Ouvrir();

            void Fermer();

            int EtatPorte();

            void Afficher(SDL_Surface*);

            void Fixer(SDL_Rect);

            ~Porte();

};

#endif // PORTE_H_INCLUDED
