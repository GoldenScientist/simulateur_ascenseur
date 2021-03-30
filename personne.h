#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "temporisateur.h"
#include "Constante.h"
#include <string>

using namespace std;

class Personne
{
    private:

            int direction;

            int pos;

            SDL_Surface *sprite;

            SDL_Rect coordonnees;

            SDL_Rect SpriteDroit[7];

            SDL_Rect SpriteGauche[7];

            Temporisateur tempmarche;

            Temporisateur tempattente;

            int indicesprite;

            int EtageDepart;

            string nomsprite;

            string partnom;


    public:
            Personne(int);

            void AllerAscenseur();

            void Disparaitre();

            void Apparaitre();

            void NewPersonne(int,int);

            int GetEtat();

            int DestinationPrecedente();

            void Marcher(int);

            void Afficher(SDL_Surface*);

            void Entrer();

            void Sortir();

            void Partir();

            void Placer(int,int,int,int);

            int Positionx();

            int Positiony();

            ~Personne();

};


#endif // PERSONNE_H_INCLUDED
