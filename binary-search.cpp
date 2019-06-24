#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <chrono>


#define maxn 2000

using namespace std::chrono;
using namespace std;

bool gr[maxn][maxn];

// Returns true if there is a possible subset 
// of size 'k' that can be a vertex cover 
bool isCover(int V, int k, int E) 
{ 
    // Set has first 'k' bits high initially 
    int set = (1 << k) - 1; 

    int limit = (1 << V); 
    // to mark the edges covered in each subset 
    // of size 'k' 
    bool vis[maxn][maxn]; 

    while (set < limit) 
    { 
        // Reset visited array for every subset 
        // of vertices 
        memset(vis, 0, sizeof vis); 

        // set counter for number of edges covered 
        // from this subset of vertices to zero 
        int cnt = 0; 

        // selected vertex cover is the the indices 
        // where 'set' has its bit high 
        for (int j = 1, v = 1 ; j < limit ; j = j << 1, v++) 
        { 
            if (set & j) 
            { 
                // Mark all edges emerging out of this 
                // vertex visited 
                for (int k = 1 ; k <= V ; k++) 
                { 
                    if (gr[v][k] && !vis[v][k]) 
                    { 
                        vis[v][k] = 1; 
                        vis[k][v] = 1; 
                        cnt++; 
                    } 
                } 
            } 
        } 

        // If the current subset covers all the edges 
        if (cnt == E) 
            return true; 

        // Generate previous combination with k bits high 
        // set & -set = (1 << last bit high in set) 
        int c = set & -set; 
        int r = set + c; 
        set = (((r^set) >> 2) / c) | r; 
    } 
    return false; 
} 

// Returns answer to graph stored in gr[][] 
int findMinCover(int n, int m) 
{ 
    // Binary search the answer 
    int left = 1, right = n; 
    while (right > left) 
    { 
        int mid = (left + right) >> 1; 
        if (isCover(n, mid, m) == false) 
            left = mid + 1; 
        else
            right = mid; 
    } 

    // at the end of while loop both left and 
    // right will be equal,/ as when they are 
    // not, the while loop won't exit the minimum 
    // size vertex cover = left = right 
    return left; 
} 

// Inserts an edge in the graph 
void insertEdge(int u, int v) 
{ 

    gr[u][v] = 1; 
    gr[v][u] = 1; // Undirected graph 
} 

void createMatrix(int vertices) 
{ 
    int i,j; //Variáveis Auxiliares
    int **gr = (int**)malloc(vertices * sizeof(int*)); //Aloca um Vetor de Ponteiros
    for (i = 0; i < vertices; i++){ //Percorre as linhas do Vetor de Ponteiros
        gr[i] = (int*) malloc(vertices * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
        for (j = 0; j < vertices; j++){ //Percorre o Vetor de Inteiros atual.
            gr[i][j] = 0; //Inicializa com 0.
        }
    }

} 



ofstream outfile("paths.txt"); //Output file

int main(int argc, char** argv)
{

    FILE *arq;
    int vertices, arestas, origem, destino;

    duration<double> time_span2;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    if (argc < 2) {
        cout << "entrada inconsistente" << endl;
        return 0;
    }
    cout << argv[1] << endl;
    arq = fopen(argv[1], "r");

    if (!arq) {
        cout << "erro ao abrir arquivo" << endl;
    }

    fscanf(arq, "p edge %d %d [\n]", &vertices, &arestas);

    //createMatrix(vertices); 

    cout << "nº vertices: " << vertices << ", nº arestas: " << arestas << endl;

    for (int i = 0; i < arestas; i++)
    {

        fscanf(arq, "e %d %d [\n]", &origem, &destino);

        //cout << "origem: " << origem << " destino: " << destino << endl;

        insertEdge(origem, destino); 

    }
    cout << "Minimum size of a vertex cover = "
        << findMinCover(vertices, arestas) << endl; 
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);


    cout << "Tempo: " << time_span.count() << endl;

   
}

