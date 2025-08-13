#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    double g, h;
    vector<pair<int, double>> neighbors; 
};

struct Compare {
    bool operator()(pair<int, double> &a, pair<int, double> &b) {
        return a.second > b.second; 
    }
};

vector<int> aStarSearch(vector<Node> &graph, int start, int goal) {
    int n = graph.size();
    vector<double> g(n, 1e9);
    vector<int> parent(n, -1);
    priority_queue<pair<int, double>, vector<pair<int, double>>, Compare> pq;

    g[start] = 0;
    pq.push({start, graph[start].h});

    while (!pq.empty()) {
        int current = pq.top().first;
        pq.pop();

        if (current == goal) break;

        for (auto &nbr : graph[current].neighbors) {
            int next = nbr.first;
            double cost = nbr.second;
            double newG = g[current] + cost;

            if (newG < g[next]) {
                g[next] = newG;
                parent[next] = current;
                pq.push({next, newG + graph[next].h});
            }
        }
    }

    vector<int> path;
    for (int at = goal; at != -1; at = parent[at]) path.push_back(at);
    reverse(path.begin(), path.end());

    cout << "Total Path Cost: " << g[goal] << "\n";
    return path;
}

int main() {
    vector<Node> graph(6);

    for (int i = 0; i < 6; i++) graph[i].id = i;

    graph[0].h = 10;
    graph[1].h = 8;
    graph[2].h = 5;
    graph[3].h = 7;
    graph[4].h = 3;
    graph[5].h = 0; 

    graph[0].neighbors = {{1, 4}, {2, 2}};
    graph[1].neighbors = {{0, 4}, {3, 5}, {4, 10}};
    graph[2].neighbors = {{0, 2}, {3, 8}};
    graph[3].neighbors = {{1, 5}, {2, 8}, {4, 2}, {5, 6}};
    graph[4].neighbors = {{1, 10}, {3, 2}, {5, 3}};
    graph[5].neighbors = {{3, 6}, {4, 3}};

    int start = 0, goal = 5;
    vector<int> path = aStarSearch(graph, start, goal);

    cout << "Path from " << start << " to " << goal << ": ";
    for (int node : path) cout << node << " ";
    cout << "\n";

    return 0;
}
