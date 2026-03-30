#include <unordered_map>
class Solution {
public:
    int characterReplacement(string s, int k) {
        // left and right pointer to expand the window
        // keep a frequency map
        // int count[26] = {0};
        vector<int> count(26, 0);
        int left = 0;
        int maxlen = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            // keep track of the highest freq
            int max_freq = max_array(count);
            if ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            else {
                maxlen = max(maxlen, right - left + 1);
            }
        }
        return maxlen;
    }
    int max_array(vector<int>& arr) {
        int max_val = 0;
        for (int i = 0; i < arr.size(); i++) {
            max_val = max(max_val, arr[i]);
        }
        return max_val;
    }
};
