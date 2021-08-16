#include <iostream>
#include <string>
#include "Fila.hpp"

#ifndef MEMORY_H
#define MEMORY_H

class Memory{
    private:
        int sizepage;
        int sizeMemory;
        int numberPages;
        long int shift;
        std::string repositionMethod;
        Fila buffer;

    public:
        Memory( std::string repositionMethod, int sizepage, int sizeMemory);
        //~Memory();    

        int calcShift();
        bool isFree();
        void rewrite(std::string data, int time);
        bool write(std::string data, int time);
        bool read(std::string data, int time);

};

#endif