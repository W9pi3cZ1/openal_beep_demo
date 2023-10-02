#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string.h>
#include <AL/alut.h>
#include <unistd.h>
#include <music.h>
#include <main.h>
using namespace std;

unsigned sample_rate = 22050; // 采样率 SampleRate : 22.05khz

void Init_AL() { // 初始化OpenAL Init OpenAL
    const char *defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
    ALCdevice* dev = alcOpenDevice(defname);
    ALCcontext *ctx = alcCreateContext(dev, NULL);

    cout << "默认设备（Default device）: " << defname << endl << endl;

    alcMakeContextCurrent(ctx);
}

void Exit_AL() { // 退出OpenAL Exit OpenAL
    ALCdevice *dev = NULL;
    ALCcontext *ctx = NULL;
    ctx = alcGetCurrentContext();
    dev = alcGetContextsDevice(ctx);

    alcMakeContextCurrent(NULL);
    alcDestroyContext(ctx);
    alcCloseDevice(dev);
}

bool flag=true; // 设置当前方波的朝向 Set the direction of the current square wave.

float SquareWaveAt(float freq,int sample_number){ // 方波的实现 Square Wave
    if(sample_number % (int)round(sample_rate / freq / 0.25) == 0){
        flag=!flag;
    }

    if(flag){
      return 1;
    }else{
      return -1;
    }
}

void Sleep(float seconds){ // 用于阻塞程序（让程序等波形播放完）
    alutSleep(seconds/1000);
}

void GenArray(float freq,float seconds,float vol,short *samples){ //生成音频
    unsigned int offset = 32760;
    size_t buf_size = seconds / 1000 * sample_rate;
    float x=0.0f;
    for(int i=0; i<buf_size; ++i) {
        x=(0.25f*float(M_PI)*freq)/sample_rate * i;

        // 这里可以自定义音色 Custom Wave

        // 合成贝斯 Synth bass
        samples[i]=0;
        for(int n=1;n<=5;n++){
            samples[i] += offset * (sin(n*x)/n) *vol;
        }

        // 正弦波 Sine Wave
        // samples[i] = offset * sin(x)*vol;

        // 三角波 Triangular wave
        // samples[i] = offset * (((asin(sin(x)))/0.5)/M_PI)*vol;

        // 方波 Square Wave
        // samples[i] = offset * SquareWaveAt(freq,i) * vol;

        // 声音衰减 Volume Fade
        vol/=1+(4/seconds/100);
    }
}

void BeepByArr(float (*arr)[3],int arrLen){ // 播放一个二维数组
    struct WaveData bufSrc[arrLen];
    for(int i=0;i<arrLen;i++){
        bufSrc[i]=Beepf(arr[i][0],arr[i][1],arr[i][2]);
    }
    for(int j=0;j<arrLen;j++){
        CleanBufSrc(bufSrc[j]);
    }
}

WaveData PlayArray(float seconds,short *samples){ // 播放带有音频信息的数组
    ALuint buf;
    alGenBuffers(1, &buf);
    // al_check_error();

    size_t buf_size = (int)(round(seconds / 1000 * sample_rate /10)*10);

    alBufferData(buf, AL_FORMAT_MONO16, samples, buf_size, sample_rate);
    // al_check_error();

    ALuint src = 0;
    alGenSources(1, &src);
    alSourcei(src, AL_BUFFER, buf);
    alSourcePlay(src);
    WaveData bufSrc = {buf,src};
    return bufSrc;
}

void CleanBufSrc(WaveData bufSrc){ // 清理残留的资源，因为一旦多了会报错
    ALuint buf = bufSrc.buf;
    ALuint src = bufSrc.src;
    alSourceStopv(1,&src);
    alDeleteSources(1,&src);
    alDeleteBuffers(1,&buf);
    // al_check_error();
}

WaveData Beepf(float freq,float seconds,float sleepTime){ // 播放三角函数的声音，但不会自动清理残留资源。

    size_t buf_size = seconds / 1000 * sample_rate;

    short *samples;
    samples = new short[buf_size];
    GenArray(freq,seconds,0.2f,samples);

    cout << "Beep(" <<(int)freq << "," << (int)seconds << ")" << endl;
    
    WaveData bufSrc = PlayArray(seconds,samples);
    Sleep(sleepTime);
    
    delete[] samples;
    return bufSrc;
}

void Beep(float freq,float seconds){ // 兼容windows官方的beep版本
    CleanBufSrc(Beepf(freq,seconds,seconds+50));
}

int main(int argc, char* argv[]) {
    Init_AL();
    play();
    Exit_AL();
    return 0;
}