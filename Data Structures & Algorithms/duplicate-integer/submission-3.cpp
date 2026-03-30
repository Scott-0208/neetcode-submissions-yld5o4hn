class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size(); // Get the number of elements

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
        // O(n^2)
    }
};