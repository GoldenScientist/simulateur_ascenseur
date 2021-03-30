#include "lumiere.h"


Lumiere::Lumiere(SDL_Surface* s):tempo1(),tempo2()
{
    ecran = s;

    activer=1;

    niveau = "1";

    ledvert=IMG_Load("ledv.png");

    ledrouge=IMG_Load("ledr.png");

    policePaneau = TTF_OpenFont("a.ttf",20);

    couleurPaneau.r = 255, couleurPaneau.g = 255, couleurPaneau.b = 255;

    //couleurPaneau = { 255, 255, 255 };


    SDL_SetColorKey(ledvert, SDL_SRCCOLORKEY, SDL_MapRGB(ledvert->format, 0, 0, 0));

    SDL_SetColorKey(ledrouge, SDL_SRCCOLORKEY, SDL_MapRGB(ledrouge->format, 0, 0, 0));

}

void Lumiere::Allumer(SDL_Rect p, int coul, int orig)
{
    SDL_Rect posPanneau;
    posPanneau.x = p.x+13;
    posPanneau.y = p.y+6;

    if(coul==ROUGE)//1
    {
        SDL_BlitSurface(ledrouge,NULL,ecran,&p);

        couleurPaneau.r = 255, couleurPaneau.g = 255, couleurPaneau.b = 255;
        if(tempo1.Chrono(800)&&activer==0)
        {
           activer=1;
        }

        if(activer==1)
        {
            if(orig==ETAGE1)//1
            {
                niveau = "2";
                panneau = TTF_RenderText_Blended(policePaneau,niveau.c_str(),couleurPaneau);
                SDL_BlitSurface(panneau,NULL,ecran,&posPanneau);
            }
            if(orig==ETAGE2)//2
            {
                niveau = "1";
                panneau = TTF_RenderText_Blended(policePaneau,niveau.c_str(),couleurPaneau);
                SDL_BlitSurface(panneau,NULL,ecran,&posPanneau);
            }

            if(tempo2.Chrono(200)&&activer==1)
           {
               activer=0;

           }

        }
    }

    if(coul==VERTE)
    {
       SDL_BlitSurface(ledvert,NULL,ecran,&p);

       couleurPaneau.r = 0, couleurPaneau.g = 0, couleurPaneau.b = 0;
       panneau = TTF_RenderText_Blended(policePaneau,niveau.c_str(),couleurPaneau);
       SDL_BlitSurface(panneau,NULL,ecran,&posPanneau);

    }
    SDL_FreeSurface(panneau);
}

Lumiere::~Lumiere()
{
    SDL_FreeSurface(ledvert);

    SDL_FreeSurface(ledrouge);

    SDL_FreeSurface(panneau);

}
