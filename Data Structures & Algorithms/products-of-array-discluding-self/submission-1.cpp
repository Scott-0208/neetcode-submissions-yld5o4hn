class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        left[0] = 1;
        vector<int> right(nums.size());
        right[nums.size() - 1] = 1;
        vector<int> result(nums.size());
        // for index 0, prod = 1
        // for index 1, prod = nums[0]*prod
        // for index 2, prod = nums[1]*prod...
        for (int i = 1; i < nums.size(); i++) {
            left[i] = nums[i - 1] * left[i - 1];
            // if ((i - 1) < 0) {
            //     prod = 1;
            // }
            // else {
            //     prod = prod * nums[i - 1];
            // }
            // pre_prod.push_back(prod);
        }
        // for index nums.size()-1, prod = 1
        // for index nums.size()-2, prod = prod*nums[nums.size-1]...
        // for index 0, prod = prod*nums[1]
        for (int i = nums.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
            // if ((i + 1) >= nums.size()) {
            //     prod = 1;
            // }
            // else {
            //     prod = prod * nums[i + 1];
            // }
            // su_prod.push_back(prod);
        }
        // Multiply two array
        for (int i = 0; i < nums.size(); i++) {
            result[i] = right[i] * left[i];
        }
        return result;
    }
};
