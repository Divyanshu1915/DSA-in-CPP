#include <iostream>
using namespace std;

void printAdjacencyMatrix(int matrix[4][4], int size) {
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    char vertexData[4] = {'A', 'B', 'C', 'D'};

    int adjacencyMatrix[4][4] = {
        {0, 1, 1, 1}, // Edges for A
        {1, 0, 1, 0}, // Edges for B
        {1, 1, 0, 0}, // Edges for C
        {1, 0, 0, 0}  // Edges for D
    };

    cout << "Vertex Data: ";
    for (int i = 0; i < 4; i++) {
        cout << vertexData[i] << " ";
    }
    cout << endl;

    printAdjacencyMatrix(adjacencyMatrix, 4);

    return 0;
}