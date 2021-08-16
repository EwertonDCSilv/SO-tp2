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
    this->shift = 0;
}

bool Memory::isFree(){
    return this->numberPages < this->buffer.getComprimento();
}

void Memory::rewrite(std::string data, int time){
    if(this->repositionMethod == "lru"){
        this->buffer.lru();
        this->buffer.insert(data, this->shift, time, 0);
    }
    else if(this->repositionMethod == "fifo"){
        this->buffer.pop();
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