class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> check;
        int left = 0;
        int max_len = 0;
        for (int right = 0; right < s.size(); right++) {
            // Found a duplicate
            while (check.count(s[right])) {
                check.erase(s[left]);
                left++;
            }
            max_len = max(max_len, right -left + 1);
            check.insert(s[right]);
        }
        return max_len;
    }
};
