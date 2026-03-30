#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. Map to store: SortedString -> List of Anagrams
        unordered_map<string, vector<string>> res;

        for (string s : strs) {
            // 2. Create a coy of thestring and sort it
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());

            // 3. Use the sorted string as a key to group the original string
            res[sortedS].push_back(s);
        }

        // 4. Convert the Map values into our final vector of vectors
        vector<vector<string>> result;
        for (auto pair : res) {
            result.push_back(pair.second); // pair.second
        }
        return result;
    }
};
