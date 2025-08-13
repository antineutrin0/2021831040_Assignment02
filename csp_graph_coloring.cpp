#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], vector<vector<int>> &graph, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] && color[i] == c) return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>> &graph, int m, int color[], int node) {
    if (node == graph.size()) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, color, graph, c)) {
            color[node] = c;
            if (graphColoringUtil(graph, m, color, node + 1)) return true;
            color[node] = 0; 
        }
    }
    return false;
}

void graphColoring(vector<vector<int>> &graph, int m) {
    int V = graph.size();
    int color[V];
    memset(color, 0, sizeof(color));

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "No solution exists with " << m << " colors.\n";
        return;
    }

    cout << "Solution exists with " << m << " colors.\n";
    cout << "Node Colors:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : Color " << color[i] << "\n";
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; 
    graphColoring(graph, m);

    return 0;
}
