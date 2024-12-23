#include <pthread.h>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    bool inside(int m, int n, int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    // 返回新被污染的橘子数
    int rot(vector<vector<int>>& grid, int x, int y, vector<pair<int, int>> &rotted_orange) {
        int new_rotted = 0;
        int m = grid.size(), n = grid[0].size();
        if (inside(m, n, x - 1, y) && grid[x - 1][y] == 1) {
            grid[x - 1][y] = 2;
            rotted_orange.push_back(make_pair(x - 1, y));
            new_rotted++;
        }
        if (inside(m, n, x + 1, y) && grid[x + 1][y] == 1) {
            grid[x + 1][y] = 2;
            rotted_orange.push_back(make_pair(x + 1, y));
            new_rotted++;
        }
        if (inside(m, n, x, y - 1) && grid[x][y - 1] == 1) {
            grid[x][y - 1] = 2;
            rotted_orange.push_back(make_pair(x, y - 1));
            new_rotted++;
        }
        if (inside(m, n, x, y + 1) && grid[x][y + 1] == 1) {
            grid[x][y + 1] = 2;
            rotted_orange.push_back(make_pair(x, y + 1));
            new_rotted++;
        }
        return new_rotted;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int start_good_orange_num = 0, start_rotted_orange_num = 0;
        vector<pair<int, int>> rotted_orange;

        // 初始化数据结构
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start_good_orange_num++;
                } else if (grid[i][j] == 2) {
                    start_rotted_orange_num++;
                    rotted_orange.push_back(make_pair(i, j));
                }
            }
        }

        // 进行若干轮橘子腐化操作，直至腐化数不再增加
        // 初始数量作比较，确定是否有剩余新鲜橘子，若有，返回 -1
        int term_cnt = 0;
        int p_rotted = 0;
        while (1) {
            int new_rotted = 0;
            int rotted_orange_now = rotted_orange.size();
            // 不要在使用迭代器遍历 vector 的时候进行 vector 修改操作！
            for (size_t i = p_rotted; i < rotted_orange_now; i++) {
                if (rotted_orange[i].first != -1) {
                    new_rotted += rot(grid, rotted_orange[i].first, rotted_orange[i].second, rotted_orange);
                    rotted_orange[i].first = -1;
                }
            }
            p_rotted = rotted_orange_now - 1;
            if (!new_rotted) {
                if (rotted_orange.size() - start_rotted_orange_num == start_good_orange_num) {
                    return term_cnt;
                } else {
                    return -1;
                }
            }
            term_cnt++;
        }
    }
};