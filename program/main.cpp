#include <iostream>
#include <fstream>
#include <string>
#include "Utilities.hpp"
#include "Memory.hpp"

int main(int argc, char** argv){

    std::string line;
    std::string nameFile;
    std::string repositionMethod;
    std::string *params =  NULL;

    int long data = 0;
    int sizeMemory = 0;
    int sizepage = 0;
    int readPages = 0;
    int writePages = 0;
    int time = 0;
    int debug = 0;

    // Talvez ...
    int fault = 0;
    int writebacks = 0;
    int hits = 0;
    int misses = 0;

    // Verify input params ToDo aceitar parametro de depuracao
    if(argc < 5 || argc > 6 ){
        std::cout << "Error: Invalid prams in comand line." << std::endl;
        std::cout << "Example of input: ./bin/tp2virtual lru arquivo.log 4 128" << std::endl << std::endl;
        return -1;
    }

    // Get params
    repositionMethod = argv[1];
    nameFile = argv[2];
    sizepage = std::stoi(argv[3]);
    sizeMemory = std::stoi(argv[4]);

    // Check if debug mode
    if(argc == 6 ){
       debug = std::stoi(argv[5]);
    }

    // Open text file
    std::ifstream fin(nameFile);

    // Init warning
    std::cout << "Executando o simulador..." << std::endl;

    // Define number pages
    Memory memory = Memory(repositionMethod, sizepage, sizeMemory, debug);

    // Creating a array for params in text file line
    params = new std::string[2];

    // Reading lines of text file
    while (std::getline(fin, line)){
        if(line.size()){

            // Processando parametros de entradas
            spliText(line," ",params);

            // Check is read ou write command
            if(params[1] == "R" || params[1] == "r"){

                data = std::stol(params[0], nullptr, 16);
                
                // Case hit
                if(memory.read(data, time) == true){
                    hits++;
                }
                
                // Case misses
                else{
                    if(memory.write(data, time) == false){
                        fault++;
                        writebacks++;
                    }
                    misses++;
                }
                readPages++;    
            }
            else if (params[1] == "W" || params[1] == "w"){

                // Case pagefault
                if(memory.write(data, time) == false){
                    fault++;
                    writebacks++;
                }
                writePages++;            
            }
            
            // Incremente time
            time++;
        }  
    }  

    // Delete array temp of params
    delete [] params;

    // Close text file
    fin.close();
    
    // Final Output
    std::cout << "Arquivo de entrada: " << nameFile << std::endl;
    std::cout << "Tamanho da memoria: " << sizeMemory << " KB" << std::endl;
    std::cout << "Tamanho das paginas: " << sizepage << " KB" << std::endl;
    std::cout << "Tecnica de reposicao: " << repositionMethod << std::endl;
    std::cout << "Paginas lidas: " << readPages << std::endl;
    std::cout << "Paginas escritas: " << writePages << std::endl;

    // Talvez ...
    std::cout << "Hits: " << hits << std::endl;
    std::cout << "Misses: " << misses << std::endl;
    std::cout << "Fault: " << fault << std::endl;
    std::cout << "Writebacks: " << writebacks << std::endl;

    return 0;
}