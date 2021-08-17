#include "Elemento.hpp"

// Construtor
Elemento::Elemento(long int data, long int shift, int time){
    this->data = data;
    this->time = time;
    this->debug = debug;
    this->lastAccess = time;
    this->addres = data >> shift;

        // Case debug 
    if(this->debug == 1){
        std::cout << "DEBUG ELEMENT: data       " << this->data << "..." << std::endl;
        std::cout << "DEBUG ELEMENT: time       " << this->time << "..." << std::endl;
        std::cout << "DEBUG ELEMENT: debug      " << this->debug << "..." << std::endl;
        std::cout << "DEBUG ELEMENT: lastAccess " << this->lastAccess << "..." << std::endl;
        std::cout << "DEBUG ELEMENT: addres     " << this->addres << "..." << std::endl;
    }
}

// Sets
void Elemento::setTime(int time){
    this->time = time;
}
void Elemento::setLastAccess(int lastAccess){
    this->lastAccess = lastAccess;
}

void Elemento::setData(long int data){
    this->data = data;
}

void Elemento::setAddres(long int addres){
    this->addres = addres;
}

// Gets
int Elemento::getTime(){
    return this->time;
}
int Elemento::getLastAccess(){
    return this->lastAccess;
}
long int Elemento::getData(){
    return this->data;
}
long int Elemento::getAddres(){
    return this->addres;
}

// Debug
void Elemento::debuging(){
    if(this->debug == 1){
        std::cout << "DEBUG ELEMENT: data       " << this->data << "..." << std::endl;
        std::cout << "DEBUG ELEMENT: time       " << this->time << "..." << std::endl;
        std::cout << "DEBUG ELEMENT: debug      " << this->debug << "..." << std::endl;
        std::cout << "DEBUG ELEMENT: lastAccess " << this->lastAccess << "..." << std::endl;
        std::cout << "DEBUG ELEMENT: addres     " << this->addres << "..." << std::endl;
    }
}