#include "Fenetre.h"
#include "planificateur.h"

int main ( int argc, char** argv )
{
    Fenetre fen;

    int retour;

    if(retour = fen.menu())
    {

        Immeuble imb(fen.GetSurface(), 2);

        Personne pers(1);

        Planificateur plan(fen.GetSurface());

        while (fen.Active())
        {
            plan.Planifier(imb,pers);
        }
    }
   return 0;
}

