#include "planificateur.h"

Planificateur::Planificateur(SDL_Surface* ecr):tempo()
{
    ecran = ecr;

    srand(time(NULL));

    aleatoire=0;

    directionPersonne=0;

    wait=0;

    prochainePersonne = 5;

    Numeropersonne=1;

    positionCompteur.x=10;

    positionCompteur.y=10;

    couleurtexte = {255, 255, 255};

    police=TTF_OpenFont("a.ttf",20);

}


void Planificateur::Planifier(Immeuble& imb , Personne& p)
{

//*************************************************condition pour sonner la cloche de l'ascensseur**********************************************



    if(((imb.HauteurAscenseur()>74)&&(imb.HauteurAscenseur()<76)&&(imb.OrigineAscenseur()==ETAGE1))||((imb.HauteurAscenseur()>364)&&(imb.HauteurAscenseur()<366)&&(imb.OrigineAscenseur()==ETAGE2)))//1-2
        {
            imb.SonnerCloche();
        }

//*****************************************condition pour changer les couleur du voyant de l'ascenseur*******************************************

    if(imb.HauteurAscenseur()>71&&imb.HauteurAscenseur()<371)
    {
        imb.AllumerLed(ROUGE);

    }
    else

    imb.AllumerLed(VERTE);

//****************************************condition permettant a une personne d'aller a l'ascenseur********************************************

    if(p.GetEtat()==VENIR)
    {
        p.Apparaitre();

        wait=0;

        p.AllerAscenseur();

        imb.Afficher();

        p.Afficher(ecran);

    }

//***************************condition pour ouvrir la porte de l'ascenseur si une personne arrive devant l'ascenseur****************************

    if(((p.GetEtat()==DEV_ASC_B)&&(imb.PositionAscenseur()==ETAGE1)&&(imb.EtatPorte(ETAGE1)==FERMER))||((p.GetEtat()==DEV_ASC_H)&&(imb.PositionAscenseur()==ETAGE2)&&(imb.EtatPorte(ETAGE2)==FERMER)))//1-1-2-1
    {
        if(imb.PositionAscenseur()==ETAGE1)
        {
            imb.OuvrirPorte(ETAGE1);
        }

        if(imb.PositionAscenseur()==ETAGE2)
        {
            imb.OuvrirPorte(ETAGE2);
        }

        imb.Afficher();

         p.Afficher(ecran);
    }

//**************************Condition de Descente ou Montee de l'ascenseur pour aller chercher une personne************************************

    if(((p.GetEtat()==DEV_ASC_B)&&(imb.PositionAscenseur()==ETAGE2))||((p.GetEtat()==DEV_ASC_H)&&(imb.PositionAscenseur()==ETAGE1)))
    {

            //******************************************Descente************************************************

        if((imb.PositionAscenseur()==ETAGE2)&&(p.GetEtat()==DEV_ASC_B))
        {
            imb.DescendreAscenseur();
        }

            //********************************************Montee**************************************************

        if((imb.PositionAscenseur()==ETAGE1)&&(p.GetEtat()==DEV_ASC_H))
        {
            imb.MonterAscenseur();
        }

        imb.Afficher();

         p.Afficher(ecran);
    }

//****************************************condition d'entree d'une personne dans l'ascenseur**************************************************

    if(((p.GetEtat()==DEV_ASC_B)&&(imb.PositionAscenseur()==ETAGE1)&&(imb.EtatPorte(ETAGE1)==OUVERT))||((p.GetEtat()==DEV_ASC_H)&&(imb.PositionAscenseur()==ETAGE2)&&(imb.EtatPorte(ETAGE2)==OUVERT)))
    {
        imb.Afficher();

        p.Entrer();

        p.Afficher(ecran);
    }

//***************************condition de fermeture de la porte d'ascenseur si une personne vient d'entrer*************************************

    if(((p.GetEtat()==DANS_ASC)&&(imb.PositionAscenseur()==ETAGE1)&&(imb.EtatPorte(ETAGE1)==OUVERT))||((p.GetEtat()==DANS_ASC)&&(imb.PositionAscenseur()==ETAGE2)&&(imb.EtatPorte(ETAGE2)==OUVERT)))
    {
        if((imb.PositionAscenseur()==ETAGE1)&&(imb.EtatPorte(ETAGE1)==OUVERT)&&(p.DestinationPrecedente()==imb.PositionAscenseur()))
        {
            imb.FermerPorte(ETAGE1);
        }

        if((imb.PositionAscenseur()==ETAGE2)&&(imb.EtatPorte(ETAGE2)==OUVERT)&&(p.DestinationPrecedente()==imb.PositionAscenseur()))
        {
            imb.FermerPorte(ETAGE2);
        }

        imb.Afficher(p);
    }

//***********************************condition de la montee ou descente de l'ascenseur avec une personne*****************************************

    if(((p.GetEtat()==DANS_ASC)&&(imb.PositionAscenseur()==ETAGE1)&&(p.DestinationPrecedente()==imb.PositionAscenseur())&&(imb.EtatPorte(ETAGE1)==FERMER))||((p.GetEtat()==DANS_ASC)&&(imb.PositionAscenseur()==ETAGE2)&&(p.DestinationPrecedente()==imb.PositionAscenseur())&&(imb.EtatPorte(ETAGE2)==FERMER)))
    {
        //******************************************Montee************************************************

        if(((imb.PositionAscenseur()==ETAGE1)&&(imb.EtatPorte(ETAGE1)==FERMER))&&(p.DestinationPrecedente()==imb.PositionAscenseur()))
        {
            imb.MonterAscenseur();
        }

        //******************************************Descente************************************************

        if(((imb.PositionAscenseur()==ETAGE2)&&(imb.EtatPorte(ETAGE2)==FERMER))&&(p.DestinationPrecedente()==imb.PositionAscenseur()))
        {
            imb.DescendreAscenseur();
        }

        p.Placer(p.Positionx(), imb.HauteurAscenseur() + 74, 0, -1);

        imb.Afficher(p);
    }

//******************************condition d'ouverture d'une porte si une personne etait a l'interieur***********************************

    if(((p.GetEtat()==DANS_ASC)&&(imb.PositionAscenseur()==ETAGE2)&&(imb.EtatPorte(ETAGE2)==FERMER)&&(p.DestinationPrecedente()!=imb.PositionAscenseur()))||(((p.GetEtat()==DANS_ASC)&&(imb.PositionAscenseur()==ETAGE1)&&(imb.EtatPorte(ETAGE1)==FERMER)&&(p.DestinationPrecedente()!=imb.PositionAscenseur()))))
    {
        p.Afficher(ecran);

        if(imb.PositionAscenseur()==ETAGE2)
        {
            imb.OuvrirPorte(ETAGE2);
        }

         if(imb.PositionAscenseur()==ETAGE1)
        {
            imb.OuvrirPorte(ETAGE1);
        }

        imb.Afficher(p);
    }

//**********************************condition de la sortie si une personne etait à l'interieur de l'ascenseur***********************************

    if(((p.GetEtat()==DANS_ASC)&&(imb.PositionAscenseur()!=p.DestinationPrecedente())&&(imb.EtatPorte(ETAGE2)==OUVERT))||((p.GetEtat()==DANS_ASC)&&(imb.PositionAscenseur()!=p.DestinationPrecedente())&&(imb.EtatPorte(ETAGE1)==OUVERT)))
    {
        imb.Afficher();

        p.Sortir();

        p.Afficher(ecran);
    }


//********************************condition de fermeture d'une porte si une personne vient de sortir de l'ascnseur*************************************

    if(((p.GetEtat()==DER_ASC)&&(imb.PositionAscenseur()==ETAGE2)&&(imb.EtatPorte(ETAGE2)==OUVERT))||((p.GetEtat()==DER_ASC)&&(imb.PositionAscenseur()==ETAGE1)&&(imb.EtatPorte(ETAGE1)==OUVERT)))
    {
        imb.Afficher();

        if((imb.PositionAscenseur()==ETAGE2)&&(imb.EtatPorte(ETAGE2)==OUVERT))

        {
            imb.FermerPorte(ETAGE2);
        }

        if((imb.PositionAscenseur()==ETAGE1)&&(imb.EtatPorte(ETAGE1)==OUVERT))

        {
            imb.FermerPorte(ETAGE1);
        }

        p.Partir();

        p.Afficher(ecran);
    }


//*******************************************condition permettant à une personne de Quitter la scene***********************************************

    if(((p.GetEtat()==DER_ASC)&&(imb.PositionAscenseur()==ETAGE2)&&(imb.EtatPorte(ETAGE2)==FERMER))||(((p.GetEtat()==DER_ASC)&&(imb.PositionAscenseur()==ETAGE1)&&(imb.EtatPorte(ETAGE1))==FERMER)))
    {
        imb.Afficher();

        p.Partir();

        p.Afficher(ecran);
    }

//*******************************************condition permettant de generer une nouvelle personne dans la scene**************************************

    imb.AfficherHeure();
    tempo.AfficherNbpers(ecran,positionCompteur,Numeropersonne);


    if(p.GetEtat()==PARTIR)
    {
        imb.Afficher();

        imb.AfficherHeure();

        tempo.AfficherNbpers(ecran,positionCompteur,Numeropersonne);
    }
    prochainePersonne= rand()%7+3;

    if(p.GetEtat()==PARTIR&&tempo.Chrono(prochainePersonne*1000))
    {

        wait=1;
    }

    if(p.GetEtat()==PARTIR&&wait==1)
    {
        aleatoire=rand()%8+1;

        directionPersonne=rand()%8+1;

        //******************************si le nommbre genere est compris entre 1 et 4*********************************

        if(aleatoire<=4)
        {
            //**********************on cree une nouvelle personne au premier au deuxiemme niveau************************

            p.NewPersonne(aleatoire%3+1,directionPersonne%2+1);

            if((directionPersonne%2+1)==GAUCHE)
            {
                p.Placer(2,490,ETAGE1, VENIR);
            }

            if((directionPersonne%2+1)==DROITE)
            {
                p.Placer(722,490,ETAGE1, VENIR);
            }
        }

        //******************************si le nommbre genere est compris entre 5 et 8*********************************

        if(aleatoire>4)
        {
            p.NewPersonne(aleatoire%3+1,directionPersonne%2+1);

            if((directionPersonne%2+1)==GAUCHE)
            {
                p.Placer(2,190,ETAGE2, VENIR);
            }

            if((directionPersonne%2+1)==DROITE)
            {
                p.Placer(722,190,ETAGE2, VENIR);
            }
        }

        Numeropersonne++;

    }

 //*****************************************************mise a jour de l'ecran*******************************************************************

    SDL_Flip(ecran);

}


Planificateur::~Planificateur()
{

}

