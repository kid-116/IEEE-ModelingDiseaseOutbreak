// https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <queue>

using namespace std;

class Solution {
	int m, n;
	int soln;
	vector<vector<bool>> visited;
	vector<vector<char>> map;
public:
	bool canExplore(int x, int y) {
		return 
			(x >= 0 && x < m) &&
			(y >= 0 && y < n) &&
			map[x][y] == '1' &&
			!visited[x][y];
	}
	void explore(const int r, const int c) {
		visited[r][c] = true;
		int x, y;
		x = r - 1, y = c;
		if(canExplore(x, y)) {
			explore(x, y);
		}
		x = r, y = c - 1;
		if(canExplore(x, y)) {
			explore(x, y);
		}
		x = r + 1, y = c;
		if(canExplore(x, y)) {
			explore(x, y);
		}
		x = r, y = c + 1;
		if(canExplore(x, y)) {
			explore(x, y);
		}
	}
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        map = grid;
        soln = 0;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(map[i][j] == '1' && !visited[i][j]) {
					explore(i, j);
					++soln;
				}
			}
		}
        return soln;
    }
};

int main() {
	vector<vector<char>> grid = {
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'}
	};
	Solution solve;
	cout << solve.numIslands(grid) << "\n";
	return 0;
}