#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
        int debug;
        std::string repositionMethod;
        std::vector<Elemento*> buffer;

    public:
        Memory( std::string repositionMethod, int sizepage, int sizeMemory, int debug);
        
        // Basic methods
        int calcShift();
        int getComprimento();
        void add(int index, long int data, int time);
        bool isFree();
        void debuging();

        // Especific methods
        bool write(long int data, int time);
        bool read(long int data, int time);
        void repositionWrite(long int data, int time);

        // Reposition methods
        int lru(int time);
        int fifo(int time);
        int random();
};
#endif