#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i: nums) {
            // 1. key: i, value: count
            freq[i]++;
        }
        // 2. Sort freq by count descendingly
        vector<pair<int, int>> freqArr(freq.begin(), freq.end());
        sort(freqArr.begin(), freqArr.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        });
        // 3. Return the first k numbers
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqArr[i].first);
        }
        return result;
    }
};
