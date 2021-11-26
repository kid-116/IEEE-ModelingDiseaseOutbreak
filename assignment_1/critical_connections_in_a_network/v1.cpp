// https://leetcode.com/problems/critical-connections-in-a-network/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<int> vec) {
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
    vector<vector<int>> soln;
    void init(int n) {
        this->n = n;
        adj.resize(n);
        disc.resize(n, INT_MAX);
        low.resize(n, INT_MAX);
        visited.resize(n, false);
        time = 0;
    }
    void find_bridges(int vertex, int parent = -1) {
        visited[vertex] = true;
        disc[vertex] = low[vertex] = ++time;
        for(int v : adj[vertex]) {
            if(!visited[v]) {
                find_bridges(v, vertex);
                low[vertex] = min(low[vertex], low[v]);
                if(low[v] > disc[vertex]) {
                    soln.push_back({vertex, v});
                }
            }
            else if(v != parent) {
                low[vertex] = min(low[vertex], disc[v]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        init(n);
        for(vector<int> connection : connections) {
            int a = connection[0], b = connection[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                find_bridges(i);
            }
        }
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
    };
    vector<vector<int>> soln = solver.criticalConnections(n, connections);
    return 0;
}