#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0) {
                break;
            }

            // 双指针模板
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> tmp{nums[i], nums[j], nums[k]};
                    ans.push_back(tmp);
                    k--;
                    // 这里是为了避免重复值
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                } else if (sum > 0) {
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};