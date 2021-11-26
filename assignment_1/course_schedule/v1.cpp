// https://leetcode.com/problems/course-schedule/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
    map<int, vector<int>> prereqs;
    vector<bool> visited;
    vector<bool> in_stack;
    int numCourses;
public:
	bool hasCycle(int course) {
		visited[course] = true;
		in_stack[course] = true;
		for(int req : prereqs[course]) {
			if(in_stack[req] || (!visited[req] && hasCycle(req))) {
				return true;
			}
		}
		in_stack[course] = false;
		return false;
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	this->numCourses = numCourses;
        for(int i = 0; i < prerequisites.size(); i++) {
            prereqs[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        visited.resize(numCourses, false);
        in_stack.resize(numCourses, false);
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(hasCycle(i)) {
                	return false;
                }
            }
        }
        return true;
    }
};

int main() {
	int numCourses = 2;
	vector<vector<int>> prerequisites = {
		{1, 0},
		{0, 1}
	};
	Solution solver;
	cout << solver.canFinish(numCourses, prerequisites) << "\n";
	return 0;
}