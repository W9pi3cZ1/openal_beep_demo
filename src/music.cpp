/*
    Star Rail - HOYO-MIX

    曲谱来自 : https://www.bilibili.com/video/BV1Zs4y1d74E/
    代码 : XSlime
*/

#include <main.h>
#include <iostream>
using namespace std;

float qdo = 262;
float qre = 294;
float qmi = 330;
float qfa = 349;
float qso = 392;
float qla = 440;
float qsi = 494;
float do2 = 523;
float re = 578;
float mi = 659;
float fa = 698;
float so = 784;
float la = 880;
float si = 988;
float do21 = 1046;
float re1 = 1175;
float mi1 = 1318;
float fa1 = 1480;
float so1 = 1568;
float la1 = 1760;
float si1 = 1976;
float do211 = 1976 + 87;
float sqdo = 277;
float sqre = 311;
float sqfa = 370;
float sqso = 415;
float sqla = 466;
float sdo = 554;
float sre = 622;
float sfa = 740;
float sso = 831;
float sla = 932;
float sdo1 = 1046;
float sre1 = 1245;
float sfa1 = 1480;
float sso1 = 1661;
float sla1 = 1865;
float pai = 600,
      sypai = pai / 3,
      ban = pai / 2,
      four = ban / 2,
      ei = four / 2;
float ting = 70;

float mg1[4][3] = {
    {so, pai, pai},
    {so, pai, pai},
    {so, pai, pai},
    {so, pai, pai}};

float mg2[9][3] = {
    {so, pai, 0},
    {fa1, sypai, sypai},
    {so1, sypai, sypai},
    {mi1, sypai, sypai},
    {so, pai, 0},
    {re1, pai * 2, pai},
    {so, pai, pai},
    {so, pai, 0},
    {do21, pai, pai},
};

float mg3[9][3] = {
    {so, pai, 0},
    {si, ban, ban},
    {do21, ban, ban},
    {so, pai, 0},
    {re1, pai * 2, pai},
    {so, pai, pai},
    {so, pai, 0},
    {re1, ban, ban},
    {so, ban, ban}};

float mg4[10][3] = {
    {so, pai, 0},
    {fa1, sypai, sypai},
    {so1, sypai, sypai},
    {mi1, sypai, sypai},
    {so, pai, 0},
    {re1, pai * 2, pai},
    {so, pai, pai},
    {so, pai, 0},
    {re1, ban, ban},
    {la1, ban, ban}};

float mg5[8][3] = {
    {fa, pai, 0},
    {re1, pai, 0},
    {si1, pai * 2, pai},
    {fa, pai, pai},
    {fa, pai * 2, 0},
    {so1, pai, pai},
    {re1, ban, ban},
    {mi1, ban, ban}};

float mg6[18][3] = {
    {qdo, sypai, 0},
    {qfa, sypai, 0},
    {fa1, sypai, 0},
    {re1, sypai, sypai},
    {so1, sypai, 0},
    {do2, sypai, 0},
    {mi1, sypai, sypai},
    {re, sypai, 0},
    {mi1, sypai, sypai},
    {re1, pai * 2, 0},
    {so, sypai, sypai},
    {re, sypai, sypai},
    {do2, sypai, sypai},
    {do2, pai, 0},
    {re, pai, pai},
    {do2, pai, 0},
    {re, pai, 0},
    {do21, pai, pai}};

float mg7[11][3] = {
    {qso, pai, 0},
    {re, pai, 0},
    {si, ban, ban},
    {do21, ban, ban},
    {re, pai, 0},
    {so, pai, 0},
    {re1, pai * 2, pai},
    {re, pai, 0},
    {so, pai, pai},
    {re1, ban, ban},
    {si, ban, ban}};

float mg8[9][3] = {
    {qfa, pai * 4, 0},
    {do2, pai * 4, 0},
    {la, pai, pai},
    {re1, ban, ban},
    {do21, ban, ban},
    {si, ban, ban},
    {so, ban, ban},
    {fa, ban, ban},
    {mi, ban, ban}};

float mg9[10][3] = {
    {qso, pai, 0},
    {re, pai, 0},
    {mi1, sypai, 0},
    {so, sypai, sypai},
    {fa1, sypai, sypai},
    {so1, sypai, sypai},
    {fa, sypai, sypai},
    {mi, sypai, sypai},
    {re, sypai, sypai + pai},
    {qso, pai, pai}};

float mg10[11][3] = {
    {qfa, pai * 4, 0},
    {do2, pai * 4, 0},
    {fa, sypai, sypai},
    {so, sypai, sypai},
    {mi, sypai, sypai},
    {re, pai, pai},
    {fa1, sypai, sypai},
    {so1, sypai, sypai},
    {mi1, sypai, sypai},
    {re1, ban, ban},
    {mi, ban, ban}};

float mg11[8][3] = {
    {qso, pai * 4, 0},
    {qsi, ban, ban},
    {do2, ban, ban},
    {re, pai, pai},
    {re1, sypai, sypai},
    {mi1, sypai, sypai},
    {do21, sypai, sypai},
    {re1, pai, pai}};

float mg12[12][3] = {
    {qfa, pai * 4, 0},
    {do2, pai, 0},
    {fa, sypai, sypai},
    {so, sypai, sypai},
    {mi, sypai, sypai},
    {re, pai, pai},
    {so1, sypai, sypai},
    {la1, sypai, sypai},
    {fa1, sypai, sypai},
    {re1, ban, ban},
    {qsi, ban, 0},
    {la, ban, ban},
};

float mg13[14][3] = {
    {qso, pai * 3, 0},
    {re, pai * 3, 0},
    {si, sypai, sypai},
    {do21, sypai, sypai},
    {re1, sypai, sypai},
    {do21, sypai, sypai},
    {si, sypai, sypai},
    {so, sypai, sypai},
    {re, ban, ban},
    {so, ban, ban},
    {qre, pai, 0},
    {qso, pai, 0},
    {re1, ban, ban},
    {mi1, ban, ban},
};

float mg14[16][3] = {
    {qdo, sypai, 0},
    {qfa, sypai, 0},
    {fa1, sypai, sypai},
    {so1, sypai, 0},
    {do2, sypai, sypai},
    {re, sypai, 0},
    {mi, sypai, sypai},
    {re, pai * 2, 0},
    {so, sypai, sypai},
    {re, sypai, sypai},
    {do2, sypai, sypai},
    {do2, pai, 0},
    {re, pai, pai},
    {do2, pai, 0},
    {re, pai, 0},
    {do21, pai, pai},
};

float mg15[12][3] = {
    {qso, pai, 0},
    {re, pai, 0},
    {si, ban, ban},
    {do21, ban, ban},
    {re1, pai * 2, 0},
    {re, pai, 0},
    {so, pai, pai},
    {re, pai, 0},
    {so, pai, pai},
    {fa, sypai, sypai},
    {mi, sypai, sypai},
    {re, sypai, sypai},
};

float mg16[6][3] = {
    {qfa, pai * 4, 0},
    {qla, pai * 4, 0},
    {do2, pai, pai},
    {do2, ban, ban},
    {re, ban, ban + pai},
    {so, pai, pai}};

float mg17[5][3] = {
    {qso, pai * 4, 0},
    {so, pai, pai},
    {do2, ban, ban},
    {so, ban, ban},
    {do21, pai * 2, pai * 2}};

float mg18[2][3] = {
    {qso, pai * 4, 0},
    {so, pai * 4, pai * 4}};

void play()
{
    cout << "Star Rail - HOYO-MIX" << endl
         << endl
         << "曲谱来自 : https://www.bilibili.com/video/BV1Zs4y1d74E/" << endl
         << "代码 : XSlime" << endl;
    BeepByArr(mg1, 4);
    BeepByArr(mg1, 4);
    BeepByArr(mg2, 9);
    BeepByArr(mg3, 9);
    BeepByArr(mg4, 10);
    BeepByArr(mg5, 8);
    BeepByArr(mg6, 18);
    BeepByArr(mg7, 11);
    BeepByArr(mg8, 9);
    BeepByArr(mg9, 10);
    BeepByArr(mg10, 11);
    BeepByArr(mg11, 8);
    BeepByArr(mg12, 12);
    BeepByArr(mg13, 14);
    BeepByArr(mg14, 16);
    BeepByArr(mg15, 12);
    BeepByArr(mg16, 6);
    BeepByArr(mg17, 5);
    BeepByArr(mg18, 2);
}