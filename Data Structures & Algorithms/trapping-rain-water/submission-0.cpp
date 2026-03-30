#include <algorithm>
class Solution {
public:
    int trap(vector<int>& height) {
        // 1. How much rain can a bar trap above itself?
        // depent on the height of the tallest bar 
        // from its left and right
        // 1-1. How to find the the tallest bars from left and right?
        // tallest_right = for (i+1 to size-1)
        // tallest_left = for (i-1 to 0)
        // So, Area = min(tallest_left, tallest_right) - height[i]
        // if Area < 0, Area = 0
        // trapped_per_bar = [Area] (0th = 0, size-1th = 0)
        // [0, 0, 2, 0, 2, 3, 2, 0, 0, 0]
        // 2. How to find max area?
        // Add all the rain trapped in the trapped_per_bar
        int len = height.size();
        int area_trapped = 0;
        for (int i = 0; i < len; i++) {
            int tallest_left = 0;
            int tallest_right = 0;
            // tallest from left
            for (int j = i - 1; j >= 0; j--) {
                if (height[j] > tallest_left) {
                    tallest_left = height[j];
                }   
            }
            // tallest from right
            for (int j = i + 1; j < len; j++) {
                if (height[j] > tallest_right) {
                    tallest_right = height[j];
                }
            }
            int area = min(tallest_left, tallest_right) - height[i];
            area_trapped += max(area, 0);
        }
        return area_trapped;
    }
};
