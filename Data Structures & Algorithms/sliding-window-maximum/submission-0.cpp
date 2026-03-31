class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for (int right = 0; right < nums.size(); right++) {
            int left_boundary = right - k + 1;
            while (!dq.empty() && nums[right] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(right);
            while (dq.front() < left_boundary) {
                dq.pop_front();
            }
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
