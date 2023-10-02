#include <AL/alut.h>

struct WaveData // 用于存放src和buf，用于清理或再次播放
{
    ALuint buf;
    ALuint src;
};

void Sleep(float seconds);
void Beep(float freq,float seconds);
WaveData Beepf(float freq,float seconds,float sleepTime);
void CleanBufSrc(WaveData bufSrc);
void BeepByArr(float (*arr)[3],int arrLen);