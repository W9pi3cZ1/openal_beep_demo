#include <main.h>

int qdo = 262;
int qre = 294;
int qmi = 330;
int qfa = 349;
int qso = 392;
int qla = 440;
int qsi = 494;
int do2 = 523;
int re = 578;
int mi = 659;
int fa = 698;
int so = 784;
int la = 880;
int si = 988;
int do21 = 1046;
int re1 = 1175;
int mi1 = 1318;
int fa1 = 1480;
int so1 = 1568;
int la1 = 1760;
int si1 = 1976;
int do211 = 1976 + 87;
int sqdo = 277;
int sqre = 311;
int sqfa = 370;
int sqso = 415;
int sqla = 466;
int sdo = 554;
int sre = 622;
int sfa = 740;
int sso = 831;
int sla = 932;
int sdo1 = 1046;
int sre1 = 1245;
int sfa1 = 1480;
int sso1 = 1661;
int sla1 = 1865;
int pai = 400,
    ban = 200,
    four = 100,
    ei = 50;
int ting = 70;

void NoteGroup1()
{
    // 第一节
    Beep(qla, pai);
    Sleep(four);
    Beep(qla, four);
    Beep(qso, four);
    Beep(qla, four);
    Beep(qla, pai);
    Sleep(four);
    Beep(qla, four);
    Beep(qso, four);
    Beep(qla, four);
    // 第二节
    Beep(qla, pai);
    Sleep(four);
    Beep(qla, four);
    Beep(qso, four);
    Beep(qla, four);
    Beep(qla, ban);
    Beep(qla, four);
    Beep(do2, four);
    Beep(re, ban);
    Beep(do2, four);
    Beep(re, four);
    // 第三节
    Beep(qla, pai);
    Sleep(four);
    Beep(qla, four);
    Beep(qso, four);
    Beep(qla, four);
    Beep(qla, pai);
    Sleep(four);
    Beep(qla, four);
    Beep(qso, four);
    Beep(qla, four);
    // 第四节
    Beep(qla, pai);
    Sleep(four);
    Beep(qla, four);
    Beep(qso, four);
    Beep(qla, four);
    Beep(re, ban);
    Beep(do2, four);
    Beep(re, four);
    Beep(do2, ban);
    Beep(qla, four);
    Beep(do2, four);
}

void NoteGroup2()
{
    // 第一节
    Beep(la, ban);
    Beep(si, ban);
    Beep(do21, ban);
    Beep(re1, ban);
    Beep(mi1, pai);
    Beep(la1, ban);
    Beep(so1, ban);
    // 第二节
    Beep(mi1, pai);
    Beep(la, pai);
    Beep(mi1, ban);
    Beep(re1, ban);
    Beep(do21, ban);
    Beep(si, ban);
    // 第三节
    Beep(la, ban);
    Beep(si, ban);
    Beep(do21, ban);
    Beep(re1, ban);
    Beep(mi1, pai);
    Beep(re1, ban);
    Beep(do21, ban);
    // 第四节
    Beep(si, ban);
    Beep(la, ban);
    Beep(si, ban);
    Beep(do21, ban);
    Beep(si, ban);
    Beep(la, ban);
    Beep(sso, ban);
    Beep(si, ban);
    // 第五节
    Beep(la, ban);
    Beep(si, ban);
    Beep(do21, ban);
    Beep(re1, ban);
    Beep(mi1, pai);
    Beep(la1, ban);
    Beep(so1, ban);
    // 第六节
    Beep(mi1, pai);
    Beep(la, pai);
    Beep(mi1, ban);
    Beep(re1, ban);
    Beep(do21, ban);
    Beep(si, ban);
    // 第七节
    Beep(la, ban);
    Beep(si, ban);
    Beep(do21, ban);
    Beep(re1, ban);
    Beep(mi1, pai);
    Beep(re1, ban);
    Beep(do21, ban);
    // 第八节
    Beep(si, pai);
    Beep(do21, pai);
    Beep(re1, pai);
    Beep(mi1, pai);
}


void NoteGroup4()
{
    // 第一节
    Beep(so1, ban);
    Beep(la1, ban);
    Beep(mi1, ban);
    Beep(re1, ban);
    Beep(mi1, pai);
    Beep(re1, ban);
    Beep(mi1, ban);
    // 第二节
    Beep(so1, ban);
    Beep(la1, ban);
    Beep(mi1, ban);
    Beep(re1, ban);
    Beep(mi1, pai);
    Beep(re1, ban);
    Beep(mi1, ban);
    // 第三节
    Beep(re1, ban);
    Beep(do21, ban);
    Beep(si, ban);
    Beep(so, ban);
    Beep(la, pai);
    Beep(so, ban);
    Beep(la, ban);
    // 第四节
    Beep(si, ban);
    Beep(do21, ban);
    Beep(re1, ban);
    Beep(mi1, ban);
    Beep(la, pai);
    Beep(mi1, ban);
    Beep(so1, ban);
}

void NoteGroup3()
{
    NoteGroup4();
    NoteGroup4();
    NoteGroup4();
    NoteGroup4();
    // 第一节
    Beep(so1, ban);
    Beep(la1, ban);
    Beep(mi1, ban);
    Beep(re1, ban);
    Beep(mi1, pai);
    Beep(re1, ban);
    Beep(mi1, ban);
    // 第二节
    Beep(so1, ban);
    Beep(la1, ban);
    Beep(mi1, ban);
    Beep(re1, ban);
    Beep(mi1, pai);
    Beep(la1, ban);
    Beep(si1, ban);
    // 第三节
    Beep(do211, ban);
    Beep(si1, ban);
    Beep(la1, ban);
    Beep(so1, ban);
    Beep(mi1, pai);
    Beep(re1, ban);
    Beep(mi1, ban);
    // 第四节
    Beep(re1, ban);
    Beep(do21, ban);
    Beep(si, ban);
    Beep(so, ban);
    Beep(la, pai);
    Beep(mi1, ban);
    Beep(so1, ban);
}

void NoteGroup6()
{
    // 第一节
    Beep(la, ban + four);
    Beep(la, four);
    Beep(la, ban);
    Beep(la, ban);
    Beep(la, ban + four);
    Beep(la, four);
    Beep(la, ban);
    Beep(la, ban);
}

void NoteGroup5()
{
    NoteGroup6();
    NoteGroup6();
    NoteGroup6();
    // 第一节
    Beep(la, ban + four);
    Beep(la, four);
    Beep(la, ban);
    Beep(la, ban);
    Beep(la, ban + four);
    Beep(la, four);
    Beep(la, ban);
    Sleep(ban);
}

void play()
{
    NoteGroup1();
    NoteGroup1();
    NoteGroup2();
    NoteGroup2();
    NoteGroup3();
    NoteGroup1();
    NoteGroup3();
    NoteGroup5();
}