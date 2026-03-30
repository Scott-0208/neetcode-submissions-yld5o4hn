class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> max_left(len, 0);
        vector<int> max_right(len, 0);
        int temp_left = 0;
        int temp_right = 0;
        int area = 0;
        for (int i = 0; i < len; i++) {
            if (i > 0) {
                temp_left = max(temp_left, height[i-1]);
            }
            max_left[i] = temp_left;
        }
        for (int i = len - 1; i >= 0; i--) {
            if (i < len - 1) {
                temp_right = max(temp_right, height[i+1]);
            }
            max_right[i] = temp_right;
        }
        for (int i = 0; i < len ; i++) {
            int a = min(max_left[i], max_right[i]) - height[i];
            area += max(a, 0);
        }
        return area;
    }
};
