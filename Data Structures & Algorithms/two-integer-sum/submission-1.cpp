class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for(int i = 0; i < nums.size(); i ++) {
            mp[nums[i]] = i; 
        }

        vector<int> res;

        for(int i = 0; i < nums.size(); i ++) {
            int diff = target - nums[i];
            if (mp.find(diff) != mp.end() && i != mp[diff]) {
                int minimum = min(mp[diff], i);

                int maximum = max(mp[diff], i);

                res.push_back(minimum);

                res.push_back(maximum);

                return res;
            }
        }
        
        return res;
    }
};
