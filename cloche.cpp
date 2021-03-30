#include "cloche.h"
#include <stdlib.h>

Cloche::Cloche()
{
    FMOD_System_Create(&f_system);
    FMOD_System_Init(f_system, 8, FMOD_INIT_NORMAL, NULL);

    FMOD_System_CreateSound (f_system, "tictac.wav", FMOD_CREATESAMPLE, 0, &tic_tac);
    FMOD_System_CreateSound (f_system, "cloche.wav", FMOD_CREATESAMPLE, 0, &tin);

}

void Cloche::SonnerCloche()
{
    FMOD_System_PlaySound (f_system, FMOD_CHANNEL_FREE, tin, 0, NULL);

}

void Cloche::Tic()
{
    FMOD_System_PlaySound (f_system, FMOD_CHANNEL_FREE, tic_tac, 0, NULL);

}

Cloche::~Cloche()
{

    FMOD_Sound_Release(tin);
    FMOD_Sound_Release(tic_tac);

    FMOD_System_Close(f_system);
    FMOD_System_Release(f_system);

}
