#include <bits/stdc++.h>

using namespace std;
 
struct Edge {
    int src, dest;
};
 
class Graph {
public:
    vector<vector<int>> adjList;
 
    Graph(vector<Edge> const &edges, int n) {
        adjList.resize(n);
 
        for (Edge edge: edges) {
            int src = edge.src;
            int dest = edge.dest;
 
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};
 
string color[] = {"", "RED", "ORANGE", "YELLOW", "GREEN", "BLACK", "BROWN", "PURPLE"};
 
void colorGraph(Graph const &graph, int n) {
    unordered_map<int, int> result;
 
    for (int u = 0; u < n; u++) {
        set<int> assigned;
 
        for (int i: graph.adjList[u]) {
            if (result[i]) {
                assigned.insert(result[i]);
            }
        }
 
        int color = 1;
        for (auto &c: assigned ) {
            if (color != c) {
                break;
            }
            color++;
        }

        result[u] = color;
    }
 
    for (int v = 0; v < n; v++) {
        cout << "The color assigned to vertex " << v << " is " << color[result[v]] << endl;
    }
}
 
int main() {
    vector<Edge> edges = { {0, 2}, {0, 4}, {0, 6}, {1, 2}, {1, 5}, {2, 3}, {3, 5}, {4, 5}, {4, 6} };
 
    int n = 7;
 
    Graph graph(edges, n);
 
    colorGraph(graph, n);

    system("pause");
    return 0;
}