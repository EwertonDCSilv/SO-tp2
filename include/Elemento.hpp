#include <iostream>
#include <string>

#ifndef ELEMENTO_H
#define ELEMENTO_H

struct Elemento{
    long int data;
    long int addres;
    int time;
    int debug;
    int lastAccess;

    // Contrutor
    Elemento(long int data, long int shift, int time, int debug);
    void setTime(int time);
    void setLastAccess(int lastAccess);
    void setData(long int data);
    void setAddres(long int addres);

    int getTime();
    int getLastAccess();
    long int getData();
    long int getAddres();
    void debuging();
};
#endif