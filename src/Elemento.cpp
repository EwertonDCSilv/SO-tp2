#include "Elemento.hpp"

Elemento::Elemento(long int data, int shift, int time){
    this->data = data;
    this->address = data >> shift;
    this->time = 0;
}

void Elemento::setTime(int time){
    this->time = time;
}

void Elemento::setData(long data){
    this->data = data;
}

void Elemento::setAddress(long address){
    this->address = address;
}

int Elemento::getTime(){
    return this->time;
}

long int Elemento::getData(){
    return this->data;
}

long int Elemento::getAddress(){
    return this->address;
}