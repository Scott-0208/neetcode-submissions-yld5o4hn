#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;
        // 1. Count each number's frequency O(n)
        for (int num : nums) {
            counts[num]++;
        }
        // 2. Create bucket: a two-dim array vector<vector<int>>
        // Index stands for num of count, so length = n + 1
        vector<vector<int>> buckets(n + 1);
        for (auto const& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }
        // 3. Search backwardly O(n)
        vector<int> res;
        for (int i = n; i >= 0; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
