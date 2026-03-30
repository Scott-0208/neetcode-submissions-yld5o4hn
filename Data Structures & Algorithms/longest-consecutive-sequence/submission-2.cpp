#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int temp = 1;
        int longest = 0;
        // Sort 'nums' ascendingly
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            if (nums[i + 1] != nums[i]) {
                if ((nums[i + 1] - nums[i]) == 1) {
                    temp++;
                }
                else {
                    longest = max(longest, temp);
                    temp = 1; // reset
                }
            }
        }
        return max(temp, longest);
    }
};
