#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string.h>
// #include <AL/al.h>
// #include <AL/alc.h>
#include <AL/alut.h>
#include <unistd.h>
#include <music.h>
using namespace std;

#define CASE_RETURN(err) case (err): return "##err"
const char* al_err_str(ALenum err) {
    switch(err) {
        CASE_RETURN(AL_NO_ERROR);
        CASE_RETURN(AL_INVALID_NAME);
        CASE_RETURN(AL_INVALID_ENUM);
        CASE_RETURN(AL_INVALID_VALUE);
        CASE_RETURN(AL_INVALID_OPERATION);
        CASE_RETURN(AL_OUT_OF_MEMORY);
    }
    return "unknown";
}
#undef CASE_RETURN

#define __al_check_error(file,line) do { ALenum err = alGetError(); for(; err!=AL_NO_ERROR; err=alGetError()) { std::cerr << "AL Error " << al_err_str(err) << " at " << file << ":" << line << std::endl; } }while(0)

#define al_check_error() \
    __al_check_error(__FILE__, __LINE__)


unsigned sample_rate = 44100;

void init_al() {
    const char *defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
    ALCdevice* dev = alcOpenDevice(defname);
    ALCcontext *ctx = alcCreateContext(dev, NULL);

    std::cout << "Default device: " << defname << std::endl;

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
    if(i % (int)round(sample_rate / freq) == 0){
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

void Beep(float freq,float seconds){
    ALuint buf;
    alGenBuffers(1, &buf);
    al_check_error();

    size_t buf_size = seconds / 1000 * sample_rate;

    short *samples;
    samples = new short[buf_size];
    float vol = 0.2;
    for(int i=0; i<buf_size; ++i) {
        // samples[i] = 32760 * sin( (2.f*float(M_PI)*freq)/sample_rate * i );
        samples[i] = (32760 * SquareWaveAt(freq,i) * vol);
        vol/=1.00008;
    }

    alBufferData(buf, AL_FORMAT_MONO16, samples, buf_size, sample_rate);
    al_check_error();


    ALuint src = 0;
    alGenSources(1, &src);
    alSourcei(src, AL_BUFFER, buf);
    alSourcePlay(src);
    cout << "Beep(" <<to_string((int)freq) << "," << to_string((int)seconds) << ")" << endl;
    Sleep((seconds+15));
    delete[] samples;

    alSourceStopv(1,&src);
    alDeleteSources(1,&src);
    alDeleteBuffers(1,&buf);
    al_check_error();
    
}

int main(int argc, char* argv[]) {
    init_al();
    play();
    exit_al();
    return 0;
}