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

unsigned sample_rate = 22050;

void init_al() {
    const char *defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
    ALCdevice* dev = alcOpenDevice(defname);
    ALCcontext *ctx = alcCreateContext(dev, NULL);

    cout << "Default device: " << defname << endl;

    alcMakeContextCurrent(ctx);
}

void exit_al() {
    ALCdevice *dev = NULL;
    ALCcontext *ctx = NULL;
    ctx = alcGetCurrentContext();
    dev = alcGetContextsDevice(ctx);

    alcMakeContextCurrent(NULL);
    alcDestroyContext(ctx);
    alcCloseDevice(dev);
}

bool flag=true;

float SquareWaveAt(float freq,int i){
    if(i % (int)round(sample_rate / freq / 0.25) == 0){
        flag=!flag;
    }

    if(flag){
      return 1;
    }else{
      return -1;
    }
}

void Sleep(float sec){
    alutSleep(sec/1000);
}

void genArray(float freq,float seconds,float vol,short *samples){
    unsigned int offset = 32760;
    size_t buf_size = seconds / 1000 * sample_rate;
    float x=0.0f;
    for(int i=0; i<buf_size; ++i) {
        x=(0.25f*float(M_PI)*freq)/sample_rate * i;
        samples[i]=0;
        for(int n=1;n<=5;n++){
            samples[i] += offset * (sin(n*x)/n) *vol;
        }
        // samples[i] = offset * sin(x)*vol; // Sine Wave
        // samples[i] = offset * (((asin(sin(x)))/0.5)/M_PI)*vol; // Triangular wave
        // samples[i] = offset * SquareWaveAt(freq,i) * vol; // Square Wave
        vol/=1+(4/seconds/100);
    }
}

void beepArr(float arr[][3],int arrLen){
    struct bufSrc bufSrc[arrLen];
    for(int i=0;i<arrLen;i++){
        bufSrc[i]=Beepf(arr[i][0],arr[i][1],arr[i][2]);
    }
    for(int j=0;j<arrLen;j++){
        cleanBufSrc(bufSrc[j]);
    }
}

struct bufSrc playArray(float seconds,short *samples){
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
    struct bufSrc bufSrc = {buf,src};
    return bufSrc;
}

void cleanBufSrc(bufSrc bufSrc){
    ALuint buf = bufSrc.buf;
    ALuint src = bufSrc.src;
    alSourceStopv(1,&src);
    alDeleteSources(1,&src);
    alDeleteBuffers(1,&buf);
    // al_check_error();
}

struct bufSrc Beepf(float freq,float seconds,float sleepT){

    size_t buf_size = seconds / 1000 * sample_rate;

    short *samples;
    samples = new short[buf_size];
    genArray(freq,seconds,0.2f,samples);

    cout << "Beep(" <<(int)freq << "," << (int)seconds << ")" << endl;
    
    bufSrc bufSrc = playArray(seconds,samples);
    Sleep(sleepT);
    
    delete[] samples;
    return bufSrc;
}

void Beep(float freq,float seconds){
    cleanBufSrc(Beepf(freq,seconds,seconds+50));
}

int main(int argc, char* argv[]) {
    init_al();
    play();
    exit_al();
    return 0;
}