// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
    int m, n;
    vector<vector<bool>> deleted;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;

    void dfs(int x, int y) {
        visited[x][y] = true;
        if(x > 0 && !deleted[x - 1][y] && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
            dfs(x - 1, y);
        }
        if(y > 0 && !deleted[x][y - 1] && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
            dfs(x, y - 1);
        }
        if(x < m - 1 && !deleted[x + 1][y] && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
            dfs(x + 1, y);
        }
        if(y < n - 1 && !deleted[x][y + 1] && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
            dfs(x, y + 1);
        }
    }
    bool has_bridge() {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    init_vis();
                    deleted[i][j] = true;
                    if(num_components() != 1) {
                        return true;
                    }
                    deleted[i][j] = false;
                }
            }
        }
        return false;
    }
    void init_vis() {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
    }
    int num_components() {
        init_vis();
        int components = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!deleted[i][j] && grid[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    ++components;
                }
            }
        }
        return components;
    }
public:
    int minDays(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        deleted.resize(m, vector<bool>(n, false));
        visited.resize(m, vector<bool>(n));
        this->grid = grid;

        // already disconnected
        if(num_components() != 1) {
            return 0;
        }
        
        if(has_bridge()) {
            return 1;
        }

        // atmost 2
        return 2;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    Solution solver;
    cout << solver.minDays(grid) << "\n";
    return 0;
}