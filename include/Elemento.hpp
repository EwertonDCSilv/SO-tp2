#include <string>

#ifndef ELEMENTO_H
#define ELEMENTO_H

struct Elemento{
    std::string data;
    int address;
    int time;
    Elemento* next;

    // Contrutor
    Elemento(std::string data, int shift, int time);
    void setTime(int time);
};

#endif