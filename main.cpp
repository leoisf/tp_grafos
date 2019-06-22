

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <vector>

using namespace std;
//using namespace std::chrono;


ofstream outfile("paths.txt"); //Output file


int main(int argc, char** argv)
{

    FILE *arq;
    int vertices, arestas, origem, destino;

    if (argc < 2) {
        cout << "entrada inconsistente" << endl;
        return 0;
    }
    cout << argv[1] << endl;
    arq = fopen(argv[1], "r");

    if (!arq) {
        cout << "erro ao abrir arquivo" << endl;
    }

    fscanf(arq, "edge %d %d [\n]", &vertices, &arestas);

    cout << "nº vertices: " << vertices << ", nº arestas: " << arestas << endl;

    for (int i = 0; i < arestas; i++)
    {

        fscanf(arq, "e %d %d [\n]", &origem, &destino);
        cout << "origem: " << origem << " destino: " << destino << endl;

    }

   
}

