class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        vector<int> v(size);

        v[size - 1] = 0;

        for(int i = size - 1; i >= 1; i --) {
            v[i - 1] = max(v[i], prices[i]);
        }


        int res = max(0, v[0] - prices[0]);

        for(int i = 1; i < size; i ++) {
            res = max(res, v[i] - prices[i]);
        }
        
        return res;
    }
};
