#include <AL/alut.h>

struct bufSrc // 用于存放src和buf，用于清理或再次播放
{
    ALuint buf;
    ALuint src;
};

void Sleep(float seconds);
void Beep(float freq,float seconds);
bufSrc Beepf(float freq,float seconds,float sleepTime);
void CleanBufSrc(bufSrc bufSrc);
void BeepByArr(float (*arr)[3],int arrLen);