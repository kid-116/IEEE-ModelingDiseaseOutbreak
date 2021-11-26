// https://leetcode.com/problems/rotting-oranges/

#include <iostream>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();
	queue<pair<int , int>> positions;
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 2) {
				positions.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}
	int mins = -1;
	while(!positions.empty()) {
		// cout << mins << "\n";
		int len = positions.size();
		for(int l = 0; l < len; l++) {
			pair<int, int> pos = positions.front();
			positions.pop();
			int i = pos.first, j = pos.second;
			// cout << i << " " << j << "\n";
			if(i > 0 && grid[i - 1][j] == 1 && (!visited[i - 1][j])) {
				positions.push(make_pair(i - 1, j));
				visited[i - 1][j] = true;
			}
			if(j > 0 && grid[i][j - 1] == 1 && (!visited[i][j - 1])) {
				positions.push(make_pair(i, j - 1));
				visited[i][j - 1] = true;
			}
			if(i < m - 1 && grid[i + 1][j] == 1 && (!visited[i + 1][j])) {
				positions.push(make_pair(i + 1, j));
				visited[i + 1][j] = true;
			}
			if(j < n - 1 && grid[i][j + 1] == 1 && (!visited[i][j + 1])) {
				positions.push(make_pair(i, j + 1));
				visited[i][j + 1] = true;
			}
		}
		++mins;
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(grid[i][j] == 1 && !visited[i][j]) {
				return -1;
			}
		}
	}
	if(mins == -1) {
		return 0;
	}
	return mins;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> grid(m, vector<int>(n));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	cout << orangesRotting(grid);
	return 0;
}