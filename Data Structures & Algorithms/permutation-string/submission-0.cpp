#include <unordered_map>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int win_size = s1.size();
        // hash table for s1
        unordered_map<char, int> s1_hash;
        unordered_map<char, int> s2_hash;
        for (int i = 0; i < win_size; i++) {
            s1_hash[s1[i]]++;
        }
        int left = 0;
        if (s2.size() < s1.size()) {
            return false;
        }
        else {
            for (int right = left + win_size - 1; right < s2.size(); right++) {
                // Build initial hash table
                if (s2_hash.size() == 0) {
                    for (int i = left; i < win_size; i++) {
                        s2_hash[s2[i]]++;
                    }
                }
                else {
                    s2_hash[s2[right]]++; // Insert new right
                    s2_hash[s2[left]]--; // Remove old left
                    left++;
                }
                // Check if the frequencies of s1's letters
                // smaller than s2's
                int num_checked = 0;
                for (auto const& cf : s1_hash) {
                    if (s2_hash[cf.first] < cf.second) {
                        break;
                    }
                    else {
                        num_checked++;
                    }
                }
                if (num_checked == s1_hash.size()) {
                    return true;
                }
            }
            return false;
        }
        
    }
};
