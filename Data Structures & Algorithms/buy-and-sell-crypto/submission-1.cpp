class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;

        int r = 1, l = 0, size = prices.size();

        while(r < size) {
            if (prices[r] > prices[l]) {
                res = max(res, prices[r] - prices[l]);
            } else {
                l = r;
            }

            r ++;
        }

        return res;
    }
};
