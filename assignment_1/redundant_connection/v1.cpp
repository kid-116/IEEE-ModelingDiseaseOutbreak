// https://leetcode.com/problems/redundant-connection/

#include <vector>

using namespace std;

class Solution {
    int n;
    vector<int> set_id;
public:
    int unionize(int a, int b) {
        if(set_id[a] == set_id[b]) {
            return -1;
        }
        int id = set_id[a];
        for(int i = 0; i < n; i++) {
            if(set_id[i] == id) {
                set_id[i] = set_id[b];
            }
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        n = edges.size();
        set_id.resize(n);
        for(int i = 0; i < n; i++) {
            set_id[i] = i;
        }
        vector<int> red = {};
        for(vector<int> edge : edges) {
            int a = edge[0] - 1, b = edge[1] - 1;
            if(unionize(a, b) == -1) {
                red = edge;
                break;
            }
        }
        return red;
    }
};