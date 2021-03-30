#include <SDL/SDL_image.h>
#include "Fenetre.h"

Fenetre::Fenetre()
{
    SDL_Init(SDL_INIT_VIDEO);

    FMOD_System_Create(&M_system);

    FMOD_System_Init(M_system, 8, FMOD_INIT_NORMAL, NULL);

    SDL_WM_SetIcon(IMG_Load("Ascenseur.png"), NULL);

    SDL_WM_SetCaption("ASCENSEUR", NULL);

    ecran = SDL_SetVideoMode(800, 600, 32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);

    done = 1;

    positionMenu.x = 0, positionMenu.y = 0;

    surfMenu = IMG_Load("Menu.png");

    FMOD_System_CreateSound (M_system, "menu.mp3", FMOD_LOOP_NORMAL, 0, &M_son);

    FMOD_Sound_SetLoopCount(M_son, -1);
}


SDL_Surface* Fenetre::GetSurface()
{
    return ecran;
}

int Fenetre::Active()
{
    SDL_PollEvent(&event);

            switch (event.type)
            {
            case SDL_QUIT:

                done = 0;

                break;
             case SDL_KEYDOWN:
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        done = 0;
                        break;
                    }
                }
            }

        return done;
}

int Fenetre::menu()
{
    SDL_BlitSurface(surfMenu, NULL, ecran, &positionMenu);

    SDL_Flip(ecran);

    FMOD_System_PlaySound (M_system, FMOD_CHANNEL_FREE, M_son, 0, NULL);

    int choix;

    while(done&&Active())
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_MOUSEBUTTONUP:
                switch(event.button.button)
                {
                case SDL_BUTTON_LEFT:
                    positionClic.x = event.button.x;
                    positionClic.y = event.button.y;
                    if((positionClic.x > 50)&&(positionClic.x < 171)&&(positionClic.y > 552)&&(positionClic.y < 583))
                    {
                        done = 0;
                        choix = 0;
                        FMOD_Sound_Release(M_son);
                        FMOD_System_Close(M_system);
                        FMOD_System_Release(M_system);
                    }
                    if((positionClic.x > 480)&&(positionClic.x < 766)&&(positionClic.y > 552)&&(positionClic.y < 583))
                    {
                        done = 0;
                        choix = 1;
                        FMOD_Sound_Release(M_son);
                        FMOD_System_Close(M_system);
                        FMOD_System_Release(M_system);
                    }
                    break;
                }
                break;
            case SDL_KEYDOWN:
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        done = 0;
                        choix = 0;
                        break;
                    }
                }
        }
    }
    if(choix==1) done=1;

return choix;
}

Fenetre::~Fenetre()
{
    SDL_FreeSurface(ecran);

    SDL_FreeSurface(surfMenu);
}

