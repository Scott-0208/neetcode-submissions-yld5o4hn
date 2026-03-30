#include <vector>
#include <unordered_map>
#include <queue> // Required for priority_queue

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Count frequencies O(n)
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }
        // 2. Define the Min-Heap
        // We store pairs of {frequency, number}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // 3. Push elements into the heap
        for (auto pair : freq) {
            // Push {frequency, number}
            minHeap.push({pair.second, pair.first});
            // If the heap is full, pop the smallest frequency
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        // 4. Extract the remaining k elements
        vector<int> result;
        while (!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
