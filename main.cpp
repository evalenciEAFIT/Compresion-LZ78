// main.cpp
#include <iostream>
#include "LZ78Compressor.h"

void showUsage() {
    std::cout << "Uso del programa:\n";
    std::cout << "  -c <archivo_entrada> <archivo_salida> : Comprime el archivo de entrada.\n";
    std::cout << "  -d <archivo_comprimido> <archivo_salida> : Descomprime el archivo comprimido.\n";
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        showUsage();
        return 1;
    }

    std::string option = argv[1];
    std::string inputFilePath = argv[2];
    std::string outputFilePath = argv[3];

    LZ78Compressor compressor;

    if (option == "-c") {
        if (compressor.compress(inputFilePath, outputFilePath)) {
            std::cout << "Archivo comprimido correctamente en: " << outputFilePath << "\n";
        } else {
            std::cerr << "Error en la compresión.\n";
        }
    } else if (option == "-d") {
        if (compressor.decompress(inputFilePath, outputFilePath)) {
            std::cout << "Archivo descomprimido correctamente en: " << outputFilePath << "\n";
        } else {
            std::cerr << "Error en la descompresión.\n";
        }
    } else {
        showUsage();
        return 1;
    }

    return 0;
}
