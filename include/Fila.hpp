#include <iostream>
#include <string>
#include "Elemento.hpp"

#ifndef FILA_H
#define FILA_H

class Fila{
    private:
        Elemento* front = NULL;
        Elemento* back = NULL;
        int comprimento = 0;

    public:
        Fila();
        ~Fila();
        
        // Retorna o tamanho da fila 
        int getComprimento();
        
        // Adciona elemento no fim da fila
        void add(std::string data, long int shift, int time);

        // Adciona elemeto na posicao i da fila
        void insert(std::string data, long int shift, int time, int index);

        // Exibe elementos da fila
        void show();

        // Remove elemento na posicao i da fila, parametro defaul = -1
        std::string pop(int index = -1);

        // ToDo: Coment
        void lru();
        void fifo();
        void random();
        bool find(long int address, int time);
        
};

#endif