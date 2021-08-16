#include <iostream>
#include <vector>
#include <string>
#include "Elemento.hpp"

#ifndef MEMORY_H
#define MEMORY_H

class Memory{
    private:
        int sizepage;
        int sizeMemory;
        int numberPages;
        int length;
        long int shift;
        std::string repositionMethod;
        std::vector<Elemento> buffer;

    public:
        Memory( std::string repositionMethod, int sizepage, int sizeMemory);
        //~Memory();    

        bool isFree();
        void rewrite(long int data, int time);
        bool write(std::string data, int time);
        bool read(std::string data, int time);
        int getLength();
        int calcShift();

        // ToDo: Coment
        void fifo(long int data, int time);
        void lru(long int data, int time);
        void random(long int data, int time);
        bool find(long int address, int time);

};

#endif