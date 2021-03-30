#include "personne.h"

using namespace std;

Personne::Personne(int etage):tempmarche(),tempattente()
{
    indicesprite = 0;

    EtageDepart=etage;

    direction=GAUCHE;//1

    if(direction==GAUCHE)//1
    {
        coordonnees.x=2;
    }

    if(direction==DROITE)//2
    {
        coordonnees.x=714;
    }

    pos=VENIR;

    if(etage==ETAGE1)//1
    {
        coordonnees.y=490;
    }

    if(etage==ETAGE2)//2
    {
        coordonnees.y=190;
    }

    nomsprite = "sprite";

    partnom="1.png";

    nomsprite+=partnom;

    sprite=IMG_Load(nomsprite.c_str());

    for(int i=0; i<7; i++)
    {
        SpriteDroit[i].x=i*57;
        SpriteDroit[i].y=0;
        SpriteDroit[i].w=57;
        SpriteDroit[i].h=100;

        SpriteGauche[i].x=i*57;
        SpriteGauche[i].y=100;
        SpriteGauche[i].w=57;
        SpriteGauche[i].h=100;
    }

}

void Personne::Placer(int x, int y, int destiPr, int po)
{
    coordonnees.x=x;

    coordonnees.y=y;

    if(destiPr==ETAGE1)//1
    {
        EtageDepart=ETAGE1;//1
    }

    if(destiPr==ETAGE2)//2
    {
        EtageDepart=ETAGE2;//2
    }

    if(po>=VENIR)
    {
        pos=po;
    }
}

void Personne::Marcher(int ordre)
{
    if(ordre==DEBOUT)
    {
         indicesprite=0;
    }
//****************************************Marche simple*****************************************************
    if((direction==GAUCHE)&&(ordre==ALLERA)&&(tempmarche.Chrono(150)))//1-1
    {
        coordonnees.x+=8;

        indicesprite++;

         if(indicesprite>6)
        {
            indicesprite=1;
        }

    }

    if((direction==DROITE)&&(ordre==ALLERA)&&(tempmarche.Chrono(150)))//2-1
    {
        coordonnees.x-=8;

        indicesprite++;

         if(indicesprite>6)
        {
            indicesprite=1;
        }

    }

//****************************************Maeche entree********************************************************
    if((direction==GAUCHE)&&(ordre==ENTREE)&&(tempmarche.Chrono(150)))//1-2
    {
        coordonnees.x+=4;

        coordonnees.y-=2;

        indicesprite++;

         if(indicesprite>6)
        {
            indicesprite=1;

            coordonnees.x+=0;
        }

    }

    if((direction==DROITE)&&(ordre==ENTREE)&&(tempmarche.Chrono(150)))//2-2
    {
        coordonnees.x-=4;

        coordonnees.y-=2;

        indicesprite++;

         if(indicesprite>6)
        {
            indicesprite=1;

            coordonnees.x+=0;
        }
    }

//****************************************Marche sortie**********************************************************
    if((direction==GAUCHE)&&(ordre==SORTIR)&&(tempmarche.Chrono(100)))//1-3
    {
        coordonnees.x+=4;

        coordonnees.y+=2;

        indicesprite++;

         if(indicesprite>6)
        {
            indicesprite=1;

            coordonnees.x+=0;
        }

    }

    if((direction==DROITE)&&(ordre==SORTIR)&&(tempmarche.Chrono(100)))//2-3
    {
        coordonnees.x-=4;

        coordonnees.y+=2;

        indicesprite++;

         if(indicesprite>6)
        {
            indicesprite=1;

            coordonnees.x+=0;
        }

    }

//**************************************************************************************************
}

void Personne::NewPersonne(int indSprt, int direct)
{

    direction = direct;

    if(direction==1)
    {
        coordonnees.x=10;
    }

    if(direction==2)
    {
        coordonnees.x=714;
    }

    nomsprite = "sprite";

    if(indSprt==1)
    {
      partnom="1.png";
    }

    if(indSprt==2)
    {
      partnom="2.png";
    }

    if(indSprt==3)
    {
      partnom="3.png";
    }

    nomsprite+=partnom;

    sprite=IMG_Load(nomsprite.c_str());
}

void Personne::AllerAscenseur()
{
    if((direction==GAUCHE&&coordonnees.x<ENTREEG)||(direction==2&&coordonnees.x>ENTREED))//1
    {
        this->Marcher(ALLERA);//1
    }

    if(((direction==GAUCHE)&&(coordonnees.x==ENTREEG)&&(coordonnees.y>400))||((direction==DROITE)&&(coordonnees.x==ENTREED)&&(coordonnees.y>400)))//1-2
    {
         pos=DEV_ASC_B;

         this->Marcher(DEBOUT);//0
    }

    if(((direction==GAUCHE)&&(coordonnees.x==ENTREEG)&&(coordonnees.y<300))||((direction==DROITE)&&(coordonnees.x==ENTREED)&&(coordonnees.y<300)))//1-2
    {
         pos=DEV_ASC_H;

         this->Marcher(DEBOUT);//0
    }
}

void Personne::Partir()
{
    if(((direction==GAUCHE)&&(coordonnees.x<820))||((direction==DROITE)&&(coordonnees.x>0)))//1-2
    {
       this->Marcher(ALLERA);//1
    }

    if(((direction==GAUCHE)&&(coordonnees.x>=748))||((direction==DROITE)&&(coordonnees.x<=0)))//1-2
    {
         this->Disparaitre();

         pos=PARTIR;
    }
}

int Personne::GetEtat()
{
    return pos;
}

void Personne::Afficher(SDL_Surface* ecr)
{

    if(direction==GAUCHE)//1
    {
        SDL_BlitSurface(sprite,&SpriteDroit[indicesprite],ecr,&coordonnees);
    }

    if(direction==DROITE)//2
    {
        SDL_BlitSurface(sprite,&SpriteGauche[indicesprite],ecr,&coordonnees);
    }
}

void Personne::Disparaitre()
{
    SDL_SetAlpha(sprite, SDL_SRCALPHA, 0);
}


void Personne::Apparaitre()
{
    SDL_SetAlpha(sprite, SDL_SRCALPHA, 255);
}

void Personne::Sortir()
{
    if(((direction==GAUCHE)&&coordonnees.x<SORTIED)||((direction==DROITE)&&(coordonnees.x>SORTIEG)))//1-2
    {
        this->Marcher(SORTIR);//3
    }

     if(((direction==GAUCHE)&&(coordonnees.x==SORTIED))||((direction==DROITE)&&(coordonnees.x==SORTIEG)))//1-2
    {
        pos=DER_ASC;
    }

}

void Personne::Entrer()
{
    if(((direction==GAUCHE)&&(coordonnees.x<362))||((direction==DROITE)&&(coordonnees.x>370)))
    {
        this->Marcher(ENTREE);//2
    }

    if(((direction==GAUCHE)&&(coordonnees.x==362))||(((direction==DROITE)&&(coordonnees.x==370))))
    {
        pos=DANS_ASC;

        this->Marcher(DEBOUT);//0

    }
}

int Personne::DestinationPrecedente()
{
    return EtageDepart;
}

int Personne::Positionx()
{
    return coordonnees.x;
}

int Personne::Positiony()
{
    return coordonnees.y;
}

Personne::~Personne()
{
    SDL_FreeSurface(sprite);
}
