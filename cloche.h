#ifndef CLOCHE_H_INCLUDED
#define CLOCHE_H_INCLUDED

#include <fmod/fmod.h>


class Cloche
{
    public:
        Cloche();

        void SonnerCloche();

        void Tic();

        virtual ~Cloche();

    private:

        FMOD_SYSTEM *f_system;
        FMOD_SOUND *tic_tac;
        FMOD_SOUND *tin;

};

#endif // CLOCHE_H_INCLUDED
