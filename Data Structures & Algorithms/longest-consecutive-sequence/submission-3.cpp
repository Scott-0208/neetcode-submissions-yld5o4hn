class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 1. Dump all numbers into a Hash Set
        // Remove duplocates automatically
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        // 2. Loop through the numbers to find starter
        for (int num : numSet) {
            if (numSet.count(num - 1)) {
                continue;
            }
            // 3. Find sequence (streak)
            int current_streak = 1;
            int current_num = num;
            while (numSet.count(current_num + 1)) {
                current_streak++;
                current_num++;
            }
            longest = max(current_streak, longest);
        }
        return longest;
    }
};
