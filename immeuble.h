#ifndef IMMEUBLE_H_INCLUDED
#define IMMEUBLE_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ascenseur.h"
#include "porte.h"
#include "personne.h"
#include "lumiere.h"
#include "cloche.h"
#include "Constante.h"

class Immeuble
{
    private:

            Cloche cloche;

            Ascenseur ascenseur;

            Porte porte1;

            Porte porte2;

            Lumiere led1;

            Lumiere led2;

            SDL_Rect positionporte1;

            SDL_Rect positionporte2;

            SDL_Rect coordonnees;

            SDL_Rect coordbarre;

            SDL_Rect positionled1;

            SDL_Rect positionled2;

            SDL_Surface* mur;

            SDL_Surface* barre;

            SDL_Surface* ecran;

            int NombreNiveau;

            Temporisateur temps;

            SDL_Rect positiontemps;

            int numcouleur;


    public:
            Immeuble(SDL_Surface*,int=1);

            void Afficher();

            void Afficher(Personne&);

            void SonnerCloche();

            void OuvrirPorte(int);

            int EtatPorte(int);

            void FermerPorte(int);

            //void FaireMarcherPersonne();

            void MonterAscenseur();

            int OrigineAscenseur();

            int PositionAscenseur();

            int HauteurAscenseur();

            void AfficherHeure();

            void AllumerLed(int);

            void DescendreAscenseur();

            ~Immeuble();
};

#endif // IMMEUBLE_H_INCLUDED
