#include "Memory.hpp"

/**
 * 
*/
Memory::Memory( std::string repositionMethod, int sizepage, int sizeMemory){
    this->sizepage = sizepage;
    this->sizeMemory = sizeMemory;
    this->numberPages = sizeMemory/sizepage;
    this->repositionMethod = repositionMethod;

    // ToDo criar metodo para calcular shift
    this->shift = this->calcShift();
}

int Memory::calcShift(){
    // ToDo criar metodo para calcular shift
    unsigned shift = 0; 
    unsigned temp = 0;
    
    temp = this->numberPages * 1024;
    while (temp>1) {
        temp = temp>>1;
        shift++;
    }

    return shift;
}

bool Memory::isFree(){
    return this->buffer.getComprimento() < this->numberPages;
}

void Memory::rewrite(std::string data, int time){
    if(this->repositionMethod == "lru"){
        this->buffer.lru();
        this->buffer.insert(data, this->shift, time, 0);
    }
    else if(this->repositionMethod == "fifo"){
        this->buffer.fifo();
        this->buffer.insert(data, this->shift, time, 0);
    }
    else if(this->repositionMethod == "random"){
        this->buffer.random();
        this->buffer.insert(data, this->shift, time, 0);
    }
}

bool Memory::write(std::string data, int time){
    if(this->isFree()){
        this->buffer.add(data, this->shift, time);
        return true;
    }
    else{
        rewrite(data, time);
        return false;
    }
}

bool Memory::read(std::string data, int time){
    long int temp = std::stol(data, nullptr, 16);
    long int address =  temp >> this->shift;;
    return this->buffer.find(address, time);
}