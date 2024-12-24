#include <vector>

using namespace std;

class Solution {
  private:
    void remove_all_near_char1(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '2';
        remove_all_near_char1(grid, i - 1, j);
        remove_all_near_char1(grid, i + 1, j);
        remove_all_near_char1(grid, i, j - 1);
        remove_all_near_char1(grid, i, j + 1);
    }

  public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    remove_all_near_char1(grid, i, j);
                } else {
                    continue;
                }
            }
        }
        return cnt;
    }
};