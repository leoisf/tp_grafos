/* 
* File:   main.cpp
* Author: Leonardo Isaac
*
* Created on 10 de Junho de 2016, 23:47
*/

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

    if (argc < 2) {
        cout << "entrada inconsistente" << endl;
        return 0;
    }
    cout << argv[1] << endl;
    ifstream inputFile(argv[1], ios::in); //abre arquivo para leitura

    if (!inputFile) {
        cout << "erro ao abrir arquivo" << endl;
    }
    int nVertices = 0; // numero de vertices
    int i = 0; // variavel auxiliar par inserção na matriz
    int aux[2]; // vetor auxiliar mpara inserção na matriz
    int** mat; // grafo

    string palavra;

    while (inputFile >> palavra) { // lê palavras do arquivo

        istringstream buffer(palavra);
        int value;
        if (buffer >> value) { // verifica se é um inteiro, caso seja atribui o valor a value

            if (nVertices == 0) { // se o valor do nº de vertices for 0 s

                nVertices = value; //atribui o primeiro valor lido a nVertice
                cout << "numero de vertices: " << nVertices << endl;
                mat = new int*[nVertices]; // aloca a matriz[nVertices][nVertices]
                for (int i = 0; i < nVertices; i++)
                    mat[i] = new int[nVertices];
                for (int i = 0; i < nVertices; i++) {
                    for (int j = 0; j < nVertices; j++) {
                        mat[i][j] = 0;
                    }
                }
            }
            else { // caso o valor de nVertices não seja 0

                if (i % 2 == 0) { // se o valor de i mod(2) = 0

                    cout << "no: " << value << endl; // leitura do no
                    aux[0] = value - 1; // posição 0 do vetor auxiliar  o No de origem
                }
                else { // se o valor de i mod(2) = ! 0

                    cout << "destino: " << value << endl; // leitura do destino
                    aux[1] = value - 1; // posição 1 do vetor auxiliar armazena No de destino
                }

                // cout << i << endl;

                if ((i % 2 != 0) && (palavra != "-1")) {

                    //cout <<"inserir: " << i+1%2 << "linha: " << aux[0]  << "col: " <<aux[1] << endl;

                    mat[aux[0]][aux[1]] = 1; // insere 1 na posição  referente ao origem / destino
                    mat[aux[1]][aux[0]] = 1; // insere 1 na posição  referente ao destino / origem
                }

                i++; // incrementa i a cada inserção, a partir da segunda leitura do arquivo, pois a primeira apenas aloca a matriz
            }

            //cout << "numeros:" << value << endl;
            //
        }
    }

   
}

