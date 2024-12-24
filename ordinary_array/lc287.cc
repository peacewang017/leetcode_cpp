#include <vector>

using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (auto num : nums) {
            if (nums[(num - 1) % (n + 1)] >= (n + 1)) {
                return num % (n + 1);
            } else {
                nums[(num - 1) % (n + 1)] += (n + 1);
            }
        }
        return -1;
    }
};