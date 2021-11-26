#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(auto vec) {
    for(auto ele : vec) {
        cout << ele << " ";
    }
    cout << "\n";
}

class Solution {
    vector<vector<int>> adj;
    vector<int> disc;
    vector<int> low;
    vector<bool> visited;
    vector<bool> is_ap;
    int time;
    int n;
    int soln;
    void init(int n) {
        this->n = n;
        adj.resize(n);
        disc.resize(n, INT_MAX);
        low.resize(n, INT_MAX);
        visited.resize(n, false);
        is_ap.resize(n, false);
        soln = 0;
        time = 0;
    }
    void find_aps(int vertex, int parent = -1) {
        visited[vertex] = true;
        disc[vertex] = low[vertex] = ++time;
        int children = 0;
        for(int v : adj[vertex]) {
            if(!visited[v]) {
                ++children;
                find_aps(v, vertex);
                low[vertex] = min(low[vertex], low[v]);
                if(parent != - 1 && low[v] >= disc[vertex]) {
                    is_ap[vertex] = true;
                    ++soln;
                }
            }
            else if(v != parent) {
                low[vertex] = min(low[vertex], disc[v]);
            }
        }
        if(parent == -1 && children > 1) {
            is_ap[vertex] = true;
            ++soln;
        }
        cout << parent << "->" << vertex << " has " << children << "\n";
    }
public:
    int criticalConnections(int n, vector<vector<int>>& connections) {
        init(n);
        for(vector<int> connection : connections) {
            int a = connection[0], b = connection[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                find_aps(i);
            }
        }
        cout << "disc:\n";
        print(disc);
        cout << "low:\n";
        print(low);
        cout << "is_ap:\n";
        print(is_ap);
        return soln;
    }
};

int main() {
    Solution solver;
    int n = 3;
    vector<vector<int>> connections = {
        {0, 1},
        {1, 2},
        {2, 0},
        // {3, 1},
        // {3, 2},
        // {4, 2},
        // {4, 3}
    };
    cout << solver.criticalConnections(n, connections) << "\n";
    return 0;
}