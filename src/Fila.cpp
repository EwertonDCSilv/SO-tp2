#include "Fila.hpp"

/*
 *  @method {Construtor da Fila}
 *  @return {void}
*/
Fila::Fila(){
    this->front = NULL;
    this->back = NULL;
    this->comprimento = 0;
}

/*
 *  @method {Destrutor da fila}
 *  @return {void}
*/
Fila::~Fila(){

    // Verifica se a fila possui elementos
    if (this->comprimento > 0){
        
        // Caminha na fila deletando pela politica FIFO.
        while (front != NULL){
            Elemento *elemento = NULL;
            elemento = this->front;
            front = front->next;
            delete elemento;
        }
    }
}

/*
 *  @method {Metodo que retorna o numero de elementos da fila}
 *  @return {int comprimento - Numero de elementos da fila}
*/
int Fila::getComprimento(){
    return this->comprimento;
}

/*
 *  @method {Metodo que adciona elemento ao inicio da fila}
 *  @param {std::string data - String de dados a serem adcionados a fila} 
 *  @return {void}
*/
void Fila::add(std::string data, long int shift, int time){
    // Criando novo elemento da fila 
    Elemento *elemento = new Elemento(data, shift, time);

    // Verifica se a fila esta vazia
    if ((this->front == this->back) && (this->comprimento == 0))    {
        
        // Inserindo elemento no inicio da fila
        this->front = elemento;
        this->back = front;
    }else{
        
        // Inserindo elemento no final da fila
        this->back->next = elemento;
        this->back = elemento;
    }

    // Incrementa comprimento da lista
    this->comprimento++;
}

/*
 *  @method {Metodo que remove o elemento na posicao i da fila}
 *  @param {int index - Indice do elemento a ser removido, aceita indices negativo (valor defaul=-1)} 
 *  @return {std::string data - Retorna o dado removido da fila}
*/
std::string Fila::pop(int index){
    Elemento *elemento = this->front;
    Elemento *elementoAnterior = NULL;
    std::string data;
    int iterator = 0;

    // Tratamento de erro: Fila vazia
    if (this->comprimento == 0 || index >= this->comprimento){
        this->front = NULL;
        this->back = NULL;
        return NULL;
    }
    
    // Verifica se o index é positivo e nao excede o comprimento da fila
    else if(index >=0 && index< this->comprimento){
        
        // Buscando elemento 
        while(elemento->next != NULL && iterator != index){
            elementoAnterior = elemento;
            elemento = elemento->next;
            iterator++;
        }
    }

    // Caminhando de forma reversa
    else {

        // Buscando elemento 
        while(elemento->next != NULL && iterator != index + this->comprimento){
            elementoAnterior = elemento;
            elemento = elemento->next;
            iterator++;
        }      
    }      
        
    // Removendo no inicio da fila
    if (elemento == this->front){
        if (this->front->next != NULL)
            this->front = this->front->next;
    } 
    
    // Removendo no fim da fila
    else if (elemento == this->back){
        elementoAnterior->next = NULL;
        this->back = elementoAnterior;
    }

    // Removendo no meio da fila
    else{
        elementoAnterior->next = elemento->next;
        elemento->next = NULL;
    }        
    
    // Decrementa comprimento da fila
    this->comprimento--;

    // Pegando dado do elemento removido 
    data = elemento->data;
    
    // Removendo elemento
    delete elemento;
    return data;
}

/*
 *  @method {Metodo que exibe os elementos da fila}
 *  @return {void}
*/
void Fila::show(){
    Elemento *elemento = this->front;

    // Verifica se a fila nao esta vazia
    if (this->comprimento > 0){

        // Exibindo elementos
        while(elemento->next != NULL){
            std::cout << elemento->data << std::endl;
            elemento = elemento->next;
        }
        std::cout << elemento->data << std::endl;
    } 
}

/*
 *  @method {Metodo que adciona elemento no indice i da fila}
 *  @param {std::string data - String dados a serem adcionados} 
 *  @param {int index - Indice da fila onde o elemento sera adcionado} 
 *  @return {void}
*/
void Fila::insert(std::string data, long int shift, int time, int index){

    // Inserindo elemento na fila vazia
    if (this->comprimento == 0){ 
        Elemento *newElemento = new Elemento(data, shift, time);
        this->front = newElemento; 
        this->back = this->front;
        this->comprimento++;
    }
    
    // Verifica de o index e positivo e naoexcede o comprimento
    else if ( index <= this->comprimento && index >=0){
        Elemento *newElemento = new Elemento(data, shift, time);
        Elemento *elemento = this->front;
        Elemento *elementoAnterior = this->front;
        int iterator = 0;
        
        // Verifica se o index nao corresponde ao primeiro elemento
        if(index > 0){

            // Caminhando na fila ate o indice correspondente
            while(iterator != index){
                elementoAnterior = elemento;
                elemento = elemento->next;
                iterator++;
            }
            elementoAnterior->next = newElemento;
            newElemento->next = elemento;
        }
        
        // Verifica se o elemento sera inserido no inicio da fila
        else{
            newElemento->next = this->front;
            this->front = newElemento;
        }
        this->comprimento++;
    }
}

void Fila::lru(){
    // ToDo implementar metodo LRU
    //this->pop();
}

void Fila::fifo(){
    // ToDo implementar metodo LRU
    //this->pop();
}
void Fila::random(){
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

/*
 *  @method {Metodo que exibe os elementos da fila}
 *  @return {void}
*/
bool Fila::find(long int address, int time){
    Elemento *elemento = this->front;

    // Verifica se a fila nao esta vazia
    if (this->comprimento > 0){

        // Exibindo elementos
        while(elemento->next != NULL){
            if (elemento->address == address){
                
                // ToDo Adicionar realocacao para LRU
                elemento->setTime(time);
                
                return true;
            }
            elemento = elemento->next;
        }
    } 
    return false;
}