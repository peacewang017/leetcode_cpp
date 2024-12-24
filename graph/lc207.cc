#include <vector>

using namespace std;

class Solution {
  private:
    bool dfs(const vector<vector<int>> &edge, vector<int> &status, int idx) {
        bool valid = true;
        status[idx] = 1;
        for (const auto &next : edge[idx]) {
            if (status[next] == 0) {
                valid = valid && dfs(edge, status, next);
            } else if (status[next] == 1) {
                return false;
            }
        }
        if (valid) {
            status[idx] = 2;
        }
        return valid;
    }

  public:
    bool canFinish_DFS(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> edge(numCourses, vector<int>{});
        vector<int> status(numCourses, 0);
        for (const auto &p : prerequisites) {
            edge[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < edge.size(); i++) {
            if (!status[i]) {
                if (!dfs(edge, status, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};