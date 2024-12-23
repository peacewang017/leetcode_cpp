#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mid = (n - 1) / 2;

        if (!(n % 2)) {
            for (int i = 0; i <= mid; i++) {
                for (int j = 0; j <= mid; j++) {
                    this->swap4(matrix, i, j);
                }
            }
        } else {
            for (int i = 0; i <= mid; i++) {
                for (int j = 0; j < mid; j++) {
                    this->swap4(matrix, i, j);
                }
            }
        }
    }

    void swap4(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();
        int tmp1 = matrix[i][j];
        int tmp2 = matrix[j][n - 1 - i];
        int tmp3 = matrix[n - 1 - i][n - 1 - j];
        int tmp4 = matrix[n - 1 - j][i];

        matrix[i][j] = tmp4;
        matrix[j][n - 1 - i] = tmp1;
        matrix[n - 1 - i][n - 1 - j] = tmp2;
        matrix[n - 1 - j][i] = tmp3;
    }
};