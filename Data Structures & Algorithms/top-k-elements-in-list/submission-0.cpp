class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int> mp;

        vector<int> unique;

        for(auto n: nums) {

            if (mp.find(n) == mp.end()) {
                unique.push_back(n);
            }
            mp[n] ++;
        }

        auto cmp = [&mp](int a, int b) {
            return mp[a] < mp[b];
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for(auto u: unique) {
            pq.push(u);
        }

        vector<int> res(k);

        for(int i = 0; i < k; i ++) {

            res[i] = pq.top();
            pq.pop();
        }

        return res;

    }

    
};
