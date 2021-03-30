#ifndef ASCENSEUR_H_INCLUDED
#define ASCENSEUR_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "temporisateur.h"
#include "Constante.h"



class Ascenseur
{
    private:

            SDL_Surface* ascenseur;

            SDL_Rect coordonnees;

            int position;

            int AttenteMontee;

            int AttenteDescente;

            int ChronoMontee;

            int ChronoDescente;

            Temporisateur tempo1;

            Temporisateur tempo2;

            int origine;

    public:

            Ascenseur();

            void Monter();

            void  Afficher(SDL_Surface*);

            void Descendre();

            int Position();

            int Origine();

            int Hauteur();

            ~Ascenseur();

};

#endif // ASCENSEUR_H_INCLUDED
