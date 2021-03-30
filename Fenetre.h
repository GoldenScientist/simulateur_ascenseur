#ifndef ECRAN_H_INCLUDED
#define ECRAN_H_INCLUDED

#include <SDL/SDL.h>
#include <fmod/fmod.h>

class Fenetre
{
    private:

            SDL_Surface* ecran;

            SDL_Surface* surfMenu;

            SDL_Rect positionMenu, positionClic;

            SDL_Event event;

            int done;

            FMOD_SYSTEM *M_system;

            FMOD_SOUND *M_son;

    public:

            Fenetre();

            SDL_Surface* GetSurface();

            int Active();

            int menu();

            ~Fenetre();
};


#endif // ECRAN_H_INCLUDED
