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

    // Reading lines of text file
    while (std::getline(fin, line)){
        if(line.size()){

            // Creating a array for params in text file line
            params = new std::string[2];

            // Processando parametros de entradas
            spliText(line," ",params);
            
            // Converting data to int
            data = std::stol(params[0], nullptr, 16);

            // Case debug 
            if(debug == 1){
                std::cout << "DEBUG MAIN: Line        " << line << "...|" << std::endl;
                std::cout << "DEBUG MAIN: params[0]   " << params[0] << "...|" << std::endl;
                std::cout << "DEBUG MAIN: params[1]   " << params[1] << "...|" << std::endl;
                std::cout << "DEBUG MAIN: data        " << data << "...|" << std::endl;
                std::cout << "************************************* ...|" << std::endl << std::endl;
            }
                
            // Check is read ou write command
            if(params[1] == "R" || params[1] == "r"){
                
                // Case debug 
                if(debug == 1){
                    std::cout << "DEBUG MAIN: read operation            ..." << std::endl;
                    std::cout << "************************************* ..." << std::endl << std::endl;
                }

                // Case hit
                if(memory.read(data, time) == true){
                    hits++;
                }
                
                // Case misses
                else{
                    // Case pagefault
                    if(memory.write(data, time) == false){
                        fault++;
                    }
                        
                }
                readPages++; 
            }
            else if (params[1] == "W" || params[1] == "w"){

                // Case debug 
                if(debug == 1){
                    std::cout << "DEBUG MAIN: write operation            ..." << std::endl;
                    std::cout << "************************************* ..." << std::endl << std::endl;
                }

                // Case pagefault
                if(memory.write(data, time) == false){
                    fault++;
                }
                writePages++;      
            }
            
            // Incremente time
            time++;
            
            // Delete array temp of params
            delete [] params;
        }  
    }  


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
    std::cout << "Time: " << time << std::endl;

    return 0;
}