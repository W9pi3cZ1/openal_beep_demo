#include <AL/alut.h>

struct bufSrc
{
    ALuint buf;
    ALuint src;
};

void Sleep(float sec);
void Beep(float freq,float seconds);
struct bufSrc Beepf(float freq,float seconds,float sleepT);
void cleanBufSrc(bufSrc bufSrc);
void beepArr(float arr[][3],int arrLen);