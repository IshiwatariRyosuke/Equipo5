#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int V = 4; // Número de vértices en el grafo

// Función para encontrar el vértice con la distancia mínima, de los que aún no han sido procesados
int minDistance(int dist[], bool sptSet[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Función para imprimir el arreglo de distancias calculadas
void printSolution(int dist[]) {
    cout << "Vertice \t Distancia desde el origen\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

// Función que implementa el algoritmo de Dijkstra para un grafo representado como una matriz de adyacencia
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // El arreglo de salida. dist[i] mantendrá la distancia más corta desde src hasta i

    bool sptSet[V]; // sptSet[i] será verdadero si el vértice i está incluido en el camino más corto

    // Inicializa todas las distancias como INFINITAS y stpSet[] como falso
    for (int i = 0; i < V; i++)
        dist[i] = INF, sptSet[i] = false;

    // La distancia del vértice origen hacia él mismo siempre es 0
    dist[src] = 0;

    // Encuentra el camino más corto para todos los vértices
    for (int count = 0; count < V - 1; count++) {
        // Toma el vértice de distancia mínima del conjunto de vértices aún no procesados
        int u = minDistance(dist, sptSet);

        // Marca el vértice elegido como procesado
        sptSet[u] = true;

        // Actualiza el valor de la dist para los vértices adyacentes del vértice elegido.
        for (int v = 0; v < V; v++)

            // Actualiza dist[v] solo si no está en sptSet, hay una arista desde u a v,
            // y el peso total del camino desde src hasta v a través de u es menor que el valor actual de dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Imprime el arreglo de distancias calculadas
    printSolution(dist);
}

int main() {
    // Representación del grafo como una matriz de adyacencia
    int graph[V][V] = {{0, 2, 6, 0},
                       {2, 0, 0, 5},
                       {6, 0, 0, 8},
                       {0, 5, 8, 0}};

    // Llamada a la función dijkstra
    dijkstra(graph, 0);

    return 0;
}
