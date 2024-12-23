#include <vector>
#include <ranges>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 这里从左下角 / 右上角进行搜索的好处在于一次比较可以排除一行 / 一列
        int i = m - 1, j = 0;

        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                i--;
            } else {
                j++;
            }
        }
        return false;
    }
};