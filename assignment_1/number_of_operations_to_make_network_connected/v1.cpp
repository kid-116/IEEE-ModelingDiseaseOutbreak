// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
	int n;
	vector<bool> visited;
	map<int, vector<int>> network;
public:
	void explore(const int node) {
		visited[node] = true;
		for(int adj : network[node]) {
			if(!visited[adj]) {
				explore(adj);
			}
		}
	}
    int numGroups() {
        int count = 0;
        for(int i = 0; i < n; i++) {
        	if(!visited[i]) {
        		explore(i);
        		++count;
        	}
		}
        return count;
    }
 	int makeConnected(int n, vector<vector<int>> &connections) {
 		this->n = n;
 		visited.resize(n, false);
 		if(connections.size() < n - 1) {
 			return -1;
 		}
 		for(vector<int> &connection : connections) {
 			int a = connection[0], b = connection[1];
 			network[a].push_back(b);
 			network[b].push_back(a);
 		}
 		return numGroups() - 1;
 	}
};

int main() {
	int n = 4;
	vector<vector<int>> connections = {
		{0, 1},
		{0, 2},
		{1, 2}
	};
	Solution solver;
	cout << solver.makeConnected(n, connections) << "\n";
	return 0;
}