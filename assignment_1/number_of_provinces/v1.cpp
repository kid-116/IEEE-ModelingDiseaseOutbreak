// https://leetcode.com/problems/number-of-islands/

#include <vector>

using namespace std;

class Solution {
	int n;
	int soln;
	vector<bool> visited;
	vector<vector<int>> hasWay;
public:
	void explore(const int city) {
		visited[city] = true;
		for(int i = 0; i < n; i++) {
			if(!visited[i] && hasWay[city][i]) {
				explore(i);
			}
		}
	}
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
       	hasWay = isConnected;
        soln = 0;
        visited.resize(n, false);
        for(int i = 0; i < n; i++) {
        	if(!visited[i]) {
        		explore(i);
        		++soln;
        	}
		}
        return soln;
    }
};