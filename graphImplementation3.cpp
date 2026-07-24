#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Graph {
private:
    vector<vector<int> > adjMatrix;
    vector<string> vertexData;
    int size;

public:
    Graph(int s) {
        size = s;
        adjMatrix.resize(size, vector<int>(size, 0));
        vertexData.resize(size);
    }

    void addEdge(int u, int v, int weight) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            adjMatrix[u][v] = weight;
            // adjMatrix[v][u] = weight;   // Uncomment for undirected graph
        }
    }

    void addVertexData(int vertex, string data) {
        if (vertex >= 0 && vertex < size) {
            vertexData[vertex] = data;
        }
    }

    void printGraph() {
        cout << "Adjacency Matrix:" << endl;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nVertex Data:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Vertex " << i << ": " << vertexData[i] << endl;
        }
    }
};

int main() {
    Graph g(4);

    g.addVertexData(0, "A");
    g.addVertexData(1, "B");
    g.addVertexData(2, "C");
    g.addVertexData(3, "D");

    g.addEdge(0, 1, 3); // A -> B with weight 3
    g.addEdge(0, 2, 2); // A -> C with weight 2
    g.addEdge(3, 0, 4); // D -> A with weight 4
    g.addEdge(2, 1, 1); // C -> B with weight 1

    g.printGraph();

    return 0;
}