#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Key 這次不是排序後的字串，而是「字母頻率表」轉換成的字串
        unordered_map<string, vector<string>> res;

        for (string s : strs) {
            // 1. 建立一長度為26的計數器，初始化為0
            vector<int> count(26, 0);
            // 2. 統計每個字母出現的次數 (O(L))
            for (char c : s) {
                count[c - 'a']++; // 'a' 對應 index 0, 'b'對應 index 1...
            }
            // 3. 將計數器轉換成一唯一的字串key (ex:"1#2#2#0#...")
            // 這樣才放進unordered_map作為key
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(count[i]);
            }
            // 4. 分組 (O(1) lookup)
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
