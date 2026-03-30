class Solution {
public:
    string minWindow(string s, string t) {
        // The "Caterpillar" (Left-to-Right)
        // The correct sliding window algorithm for this:
        // initialization: left = 0, right = 0
        // (Expand right until valid
        // Shrink left until invalid, record size)
        // Repeat
        // Note: never use "+=" on strings,
        // 1. instead using min_start and min_len adn doing s.substr()
        // changing size of requires reallocating memory
        // 2. Use vector instead of unordered_map (slow)
        // 3. "Match Counter": required & matched
        if (s.size() < t.size()) {
            return "";
        }
        vector<int> s_map(128, 0);
        vector<int> t_map(128, 0);
        for (int i = 0; i < t.size(); i++) {
            t_map[t[i]]++;
        }
        // the caterpillar sliding window
        int left = 0; // intialization
        int right = 0;
        int min_len = INT_MAX;
        int min_left = 0;
        while (left < s.size()) {
            if (check_valid(t_map, s_map)) {
                // min_len = min(min_len, right - left + 1);
                if (min_len > right - left) {
                    min_len = right - left;
                    min_left = left;
                }
                s_map[s[left]]--;
                left++; // Shrink
            } else {
                if (right == s.size()) {
                    break;
                }
                s_map[s[right]]++;
                right++; // Expand
            }
        }
        if (min_len == INT_MAX) {
            return "";
        } else {
            return s.substr(min_left, min_len);
        }
    }
    bool check_valid(const vector<int>& map1, const vector<int>& map2) {
        for (int i = 0; i < map1.size(); i++) {
            if (map1[i] > map2[i]) {
                return false;
            }
        }
        return true;
    }
};
