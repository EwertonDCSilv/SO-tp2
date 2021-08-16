#include "Memory.hpp"


//________________________       Costrutor          _______________________//
Memory::Memory( std::string repositionMethod, int sizepage, int sizeMemory){
    
    this->sizepage = sizepage;
    this->sizeMemory = sizeMemory;
    this->numberPages = sizeMemory/sizepage;
    this->repositionMethod = repositionMethod;
    this->length = 0;

    // Creating dynamic vector for memory
    for(int i=0; i < this->numberPages; i++){
        Elemento elemento = Elemento(-1,-1, -1);
        this->buffer.push_back(elemento);
    }

    this->shift = this->calcShift();
}
//========================================================================//


//________________________Metodos basicos da classe_______________________//
int Memory::getLength(){
    return this->length;
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
    return this->getLength() < this->numberPages;
}
//========================================================================//


//____________________ Metodos de operação da memoria ____________________//
bool Memory::find(long int address, int time){
       
    for(int i =0; i< this->getLength(); i++){
        if (this->buffer[i].getAddress() == address){
            
            // ToDo Adicionar realocacao para LRU
            this->buffer[i].setTime(time);
            
            return true;
        }
    } 
    return false;
}

void Memory::rewrite(long int data, int time){
    if(this->repositionMethod == "lru")
        this->removeLru(data, time);
    
    else if(this->repositionMethod == "fifo")
        this->removeFifo(data, time);
    
    else if(this->repositionMethod == "random")
        this->removeRandom(data, time);
}

bool Memory::write(std::string data, int time){
    if(this->isFree()){
        if(this->repositionMethod == "lru")
            this->addLru(data, time);
        
        else if(this->repositionMethod == "fifo")
            this->addFifo(data, time);
        
        else if(this->repositionMethod == "random")
            this->addRandom(data, time);
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
    return this->find(address, time);
}
//========================================================================//


//____________________ Method de regupamento ____________________//
void Memory::lru(long int data, int time){
    // ToDo implementar metodo LRU
    //this->pop();
}
void Memory::fifo(long int data, int time){
    // ToDo implementar metodo LRU
    //this->pop();
}
void Memory::random(long int data, int time){
    // ToDo implementar metodo Random
    /*
    	writes++;
        srand(time(NULL));	
        int index = rand() % usedPages;
        Page *tmp = first;
        for(int i = 0; i < index; i++){
            tmp = tmp->next;
        }
        strcpy(tmp->address, value);
    */
    //this->pop();
}
//========================================================================//