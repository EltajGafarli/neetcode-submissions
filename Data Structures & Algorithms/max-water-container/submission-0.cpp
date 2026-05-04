class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size = heights.size();
        int l = 0, r = size - 1;

        int res = 0;

        while(l < r) {
            int diff = r - l;
            int hdiff = min(heights[r], heights[l]);
            
            res = max(res, hdiff * diff);

            if (heights[r] < heights[l]) {
                r --;
            } else {
                l ++;
            }
            
        }

        return res;
    }
};
