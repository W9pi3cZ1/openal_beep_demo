# OpenAL Beep Demo

Beep函数音乐的播放器，但是使用OpenAL播放。（还只是个Demo）

## 咋编译它？


### 在linux平台上

1. 确保你装了OpenAL的SDK.
2. 在终端上执行以下命令用于编译

```bash
g++ -fdiagnostics-color=always -g -I ./include ./src/*.cpp -o ./build/demo -lopenal -lalut

```

### 在windows平台上

对不起，我们没有尝试在Windows上编译这个项目。:(