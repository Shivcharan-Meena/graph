#include<iostream>
#include<unordered_map>
#include<list>
#include<ctime>
#include<cstdlib>

using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void build(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs_help(unordered_map<int, bool>& visited, list<int>& ans, int node) {
        visited[node] = true;
        ans.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs_help(visited, ans, neighbor);
            }
        }
    }

    void dfs() {
        unordered_map<int, bool> visited;
        list<int> ans;

        // Loop over the unordered_map to start DFS
        for (auto& pair : adj) {
            if (!visited[pair.first]) {
                dfs_help(visited, ans, pair.first);
            }
        }

        // Print the DFS result
        for (int node : ans) {
            cout << node << " ";
        }
        cout << endl;
    }

    void print() {
        for (auto& pair : adj) {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    srand(time(0));

    Graph g;
    g.build(0, 1);
    g.build(1, 2);
    g.build(2, 3);
    g.build(3, 4);
    g.build(4, 5);

    cout << "Graph structure:" << endl;
    g.print();

    // Run DFS multiple times to check the result consistency
    cout << "DFS traversal (Run 1): ";
    g.dfs();
    
    cout << "DFS traversal (Run 2): ";
    g.dfs();
    
    cout << "DFS traversal (Run 3): ";
    g.dfs();
    
    return 0;
}
