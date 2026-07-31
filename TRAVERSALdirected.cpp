#include <iostream>
#include <vector>
using namespace std;

struct Graph {
    vector<vector<int>> adj_matrix;
    vector<char> vertex_data;
    int size;

    Graph(int size) {
        this->size = size;
        adj_matrix.resize(size, vector<int>(size, 0));
        vertex_data.resize(size);
    }

    void add_edge(int u, int v) {
        if (u >= 0 && u < size && v >= 0 && v < size) {
            adj_matrix[u][v] = 1;
            // adj_matrix[v][u] = 1; // Uncomment for undirected graph
        }
    }

    void add_vertex_data(int vertex, char data) {
        if (vertex >= 0 && vertex < size) {
            vertex_data[vertex] = data;
        }
    }

    void print_graph() {
        cout << "Adjacency Matrix:\n";

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "\nVertex Data:\n";

        for (int i = 0; i < size; i++) {
            cout << "Vertex " << i << ": " << vertex_data[i] << "\n";
        }
    }

    // Utility function for DFS
    void dfs_util(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << vertex_data[v] << " ";

        for (int i = 0; i < size; i++) {
            if (adj_matrix[v][i] == 1 && !visited[i]) {
                dfs_util(i, visited);
            }
        }
    }

    // Depth-First Search
    void dfs(char start_vertex_data) {
        vector<bool> visited(size, false);
        int start_vertex = -1;

        for (int i = 0; i < size; i++) {
            if (vertex_data[i] == start_vertex_data) {
                start_vertex = i;
                break;
            }
        }

        if (start_vertex != -1) {
            dfs_util(start_vertex, visited);
        }
    }

    // Breadth-First Search
    void bfs(char start_vertex_data) {
        vector<bool> visited(size, false);
        vector<int> queue;

        int start_vertex = -1;

        for (int i = 0; i < size; i++) {
            if (vertex_data[i] == start_vertex_data) {
                start_vertex = i;
                break;
            }
        }

        if (start_vertex != -1) {
            queue.push_back(start_vertex);
            visited[start_vertex] = true;

            int front = 0;

            while (front < queue.size()) {
                int current_vertex = queue[front++];

                cout << vertex_data[current_vertex] << " ";

                for (int i = 0; i < size; i++) {
                    if (adj_matrix[current_vertex][i] == 1 &&
                        !visited[i]) {

                        queue.push_back(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
};

int main() {
    Graph g(7);

    g.add_vertex_data(0, 'A');
    g.add_vertex_data(1, 'B');
    g.add_vertex_data(2, 'C');
    g.add_vertex_data(3, 'D');
    g.add_vertex_data(4, 'E');
    g.add_vertex_data(5, 'F');
    g.add_vertex_data(6, 'G');

    g.add_edge(3, 0); // D -> A
    g.add_edge(3, 4); // D -> E
    g.add_edge(4, 0); // E -> A
    g.add_edge(0, 2); // A -> C
    g.add_edge(2, 5); // C -> F
    g.add_edge(2, 6); // C -> G
    g.add_edge(5, 1); // F -> B
    g.add_edge(1, 2); // B -> C

    g.print_graph();

    cout << "\nDepth First Search starting from vertex D:\n";
    g.dfs('D');

    cout << "\n\nBreadth First Search starting from vertex D:\n";
    g.bfs('D');

    return 0;
}