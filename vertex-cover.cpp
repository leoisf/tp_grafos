
// Program to print Vertex Cover of a given undirected graph 
#include<iostream> 
#include <list> 
using namespace std; 
#include <chrono>

using namespace std;
using namespace std::chrono;


  
// This class represents a undirected graph using adjacency list  
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;  // Pointer to an array containing adjacency lists 
public: 
    Graph(int V);  // Constructor 
    void addEdge(int v, int w); // function to add an edge to graph 
    void printVertexCover();  // prints vertex cover 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
    adj[w].push_back(v); // Since the graph is undirected 
} 
  
// The function to print vertex cover 
void Graph::printVertexCover() 
{ 
    // Initialize all vertices as not visited. 
    bool visited[V]; 
    for (int i=0; i<V; i++) 
        visited[i] = false; 
  
    list<int>::iterator i; 
  
    // Consider all edges one by one 
    for (int u=0; u<V; u++) 
    { 
        // An edge is only picked when both visited[u] and visited[v] 
        // are false 
        if (visited[u] == false) 
        { 
            // Go through all adjacents of u and pick the first not 
            // yet visited vertex (We are basically picking an edge 
            // (u, v) from remaining edges. 
            for (i= adj[u].begin(); i != adj[u].end(); ++i) 
            { 
                int v = *i; 
                if (visited[v] == false) 
                { 
                     // Add the vertices (u, v) to the result set. 
                     // We make the vertex u and v visited so that 
                     // all edges from/to them would be ignored 
                     visited[v] = true; 
                     visited[u]  = true; 
                     break; 
                } 
            } 
        } 
    } 
  
    // Print the vertex cover 
    for (int i=0; i<V; i++) 
        if (visited[i]) 
          cout << i << " "; 
} 
  
// Driver program to test methods of graph class 
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

    Graph g(vertices); 

    for (int i = 0; i < arestas; i++)
    {

        fscanf(arq, "e %d %d [\n]", &origem, &destino);

        cout << "origem: " << origem << " destino: " << destino << endl;

        g.addEdge(origem, destino); 

    }
    
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);


    cout << "Tempo: " << time_span.count() << endl;

  
    g.printVertexCover(); 
  
    return 0; 
} 
