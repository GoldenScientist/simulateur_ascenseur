#ifndef PLANIFICATEUR_H_INCLUDED
#define PLANIFICATEUR_H_INCLUDED

#include <SDL/SDL.h>
#include "immeuble.h"
#include "personne.h"
#include "temporisateur.h"
#include "Constante.h"
#include <time.h>


class Planificateur
{
    private:
            SDL_Surface* ecran;

            SDL_Surface* z_prochain;

            SDL_Rect positionCompteur;

            TTF_Font *police;

            SDL_Color couleurtexte;

            int aleatoire;

            int directionPersonne;

            int Numeropersonne;

            int wait;

            int prochainePersonne;

            Temporisateur tempo;

    public:
            Planificateur(SDL_Surface*);

            void Planifier(Immeuble&,Personne&);

            ~Planificateur();


};

#endif // PLANIFICATEUR_H_INCLUDED
