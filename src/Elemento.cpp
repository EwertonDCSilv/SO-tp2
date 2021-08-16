#include "Elemento.hpp"

/*
 *  @method {Funcao construtora do tipo Elemento}
 *  @param {std::string data - Dado do Elemento} 
 *  @return {void}
*/
Elemento::Elemento(std::string data, int shift, int time){
    this->data = data;
    this->address = std::stol(data, nullptr, 16) >> shift;
    this->time = time;
    this->next = NULL;
}

void Elemento::setTime(int time){
    this->time = time;
}
