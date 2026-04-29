class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;

        for(int i = 0; i < nums.size(); i ++) {
            mp[nums[i]] ++;
        }

        map<int, int> cnt;

        for(int i = 0; i < nums.size(); i ++) {
            int num = nums[i];

            if (mp.find(num - 1) == mp.end()) {
                cnt[num] = 1;
            }
        }

        int res = 0;


        for(auto p: cnt) {
            int count = 1;
            int f = p.first + 1;
            while(mp[f]) {
                count ++;
                f ++;
            }

            res = max(res, count);
        }

        return res;
    }
};
