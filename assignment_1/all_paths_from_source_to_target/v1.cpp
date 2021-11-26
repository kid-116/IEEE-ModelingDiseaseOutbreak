// https://leetcode.com/problems/all-paths-from-source-to-target/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> solutions;
    queue<vector<int>> active_paths;
    active_paths.push({0});
    while(!active_paths.empty()) {
        vector<int> path = active_paths.front();
        active_paths.pop();
        int last = path[path.size() - 1];
        for(int i = 0; i < graph[last].size(); i++) {
            vector<int> branch = path;
            branch.push_back(graph[last][i]);
            if(graph[last][i] == n - 1) {
                solutions.push_back(branch);
            }
            else {
                active_paths.push(branch);
            }
        }
    }
    return solutions;
}

int main() {
    // vector<vector<int>> graph = {
    //     {1, 2},
    //     {3},
    //     {3},
    //     {}
    // };
    vector<vector<int>> graph = {
        {1, 2, 3},
        {2},
        {3},
        {}
    };
    vector<vector<int>> solns = allPathsSourceTarget(graph);
    for(vector<int> &soln : solns) {
        for(int node : soln) {
            cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}