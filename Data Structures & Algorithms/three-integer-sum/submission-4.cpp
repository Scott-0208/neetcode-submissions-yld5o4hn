#include <algorithm>
#include <unordered_set>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array (-4, -1, -1, 0, 1, 2)
        // Fix one number, do the two sum II to the rest
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            int residual = 0 - nums[i];
            while (left < right) {
                int left_val = nums[left];
                int right_val = nums[right];
                if (left_val + right_val == residual) {
                    result.push_back({nums[i], left_val, right_val});
                    // Cuz arraay is sorted,
                    // so it's impossible that
                    // only left++ or right-- leads to the right pair
                    right--;
                    left++;
                    // Duplicate skipping
                    while (left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                    while (left < right && nums[right] == nums[right+1]) {
                        right--;
                    }
                }
                else if (left_val + right_val > residual) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return result;
}};
