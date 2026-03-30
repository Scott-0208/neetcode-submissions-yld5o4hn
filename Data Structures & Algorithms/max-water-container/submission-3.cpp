class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0, end = heights.size() - 1;
        int max_vol = 0;
        while (start < end) {
            int current_vol = 0;
            int w = end - start;
            int h = min(heights[start], heights[end]);
            if (heights[start] < heights[end]) {
                start++;
            }
            else {
                end--;
            }
            current_vol = w*h;
            max_vol = max(current_vol, max_vol);
        }
        return max_vol;
    }
};
