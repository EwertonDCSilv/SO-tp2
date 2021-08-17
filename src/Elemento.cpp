#include "Elemento.hpp"

// Construtor
Elemento::Elemento(long int data, long int shift, int time, int debug){
    this->data = data;
    this->time = time;
    this->debug = debug;
    this->lastAccess = time;
    this->addres = data >> shift;

        // Case debug 
    if(this->debug == 1){
        std::cout << "DEBUG ELEMENT CONSTRUCT: data       " << this->data << "..." << std::endl;
        std::cout << "DEBUG ELEMENT CONSTRUCT: time       " << this->time << "..." << std::endl;
        std::cout << "DEBUG ELEMENT CONSTRUCT: debug      " << this->debug << "..." << std::endl;
        std::cout << "DEBUG ELEMENT CONSTRUCT: lastAccess " << this->lastAccess << "..." << std::endl;
        std::cout << "DEBUG ELEMENT CONSTRUCT: addres     " << this->addres << "..." << std::endl;
        std::cout << "************************************* ..." << std::endl << std::endl;
    }
}

// Sets
void Elemento::setTime(int time){
    this->time = time;

    // Case debug 
    this->debuging();
}
void Elemento::setLastAccess(int lastAccess){
    this->lastAccess = lastAccess;

    // Case debug 
    this->debuging();
}

void Elemento::setData(long int data){
    this->data = data;

    // Case debug 
    this->debuging();
}

void Elemento::setAddres(long int addres){
    this->addres = addres;

    // Case debug 
    this->debuging();
}

// Gets
int Elemento::getTime(){
    // Case debug 
    this->debuging();

    return this->time;
}
int Elemento::getLastAccess(){
    // Case debug 
    this->debuging();
    
    return this->lastAccess;
}
long int Elemento::getData(){
    // Case debug 
    this->debuging();

    return this->data;
}
long int Elemento::getAddres(){
    // Case debug 
    this->debuging();

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
        std::cout << "************************************* ..." << std::endl << std::endl;
    }
}