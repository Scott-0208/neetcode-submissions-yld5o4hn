class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> is to define the output (a integer vectoor)
        // vector<int>& nums is to define the input (a integer vector and an integer)
        // Naive approache:
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {}; // Fallback return to keep the compiler happy
    }
};
