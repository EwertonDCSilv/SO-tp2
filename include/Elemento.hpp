#include <string>

#ifndef ELEMENTO_H
#define ELEMENTO_H

class Elemento{
    private:
        long int data;
        int address;
        int time;
    
    public:
        // Contrutor
        Elemento(long int data, int shift, int time);
        
        // Set
        void setTime(int time);
        void setData(long data);
        void setAddress(long address); 
        
        // Get
        int getTime();
        long int getData();
        long int getAddress();
};

#endif