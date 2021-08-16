#include "Utilities.hpp"

/*
 *  @method {Separa uma string por um determinado caracter}
 *  @param {std::string text - String a ser separada} 
 *  @param {const char* separator - Caracter de separacao da string} 
 *  @param {std::string* params - Vetor de string que armazena as substrings particionadas} 
 *  @return {int numberParams - Numero de tokens}
*/
int spliText(std::string text, const char *separator, std::string *params){
    
    int numberParams = 0;
    char *temp =  NULL;
    std::string aux;

    // Alocando espaço para text
    temp = new char[text.size() + 1];

    // Copiando string para char
    std::copy(text.begin(), text.end(), temp);
    temp[text.size()] = '\0';

    // Extraindo primeiro token
    char * token = strtok(temp, separator);

    // Processando string ate o token 
    while( token != NULL ) {

        // Adicionando dados ao vetor de parametros
        aux = std::string(token);
        params[numberParams] = aux;
        token = strtok(NULL, separator);
        numberParams++;
    }

    // Removendo da memoria string temporaria
    delete [] temp;
    return numberParams;
}