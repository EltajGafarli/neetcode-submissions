class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> pref(size);
        vector<int> suff(size);

        pref[0] = 1;
        
        suff[size - 1] = 1;

        for(int i = 1; i < size; i ++) {
            pref[i] = pref[i - 1] * nums[i - 1];
        }

        for(int i = size - 1; i >= 1; i --) {
            suff[i - 1] = suff[i] * nums[i];
        }


        for(int i = 0; i < size; i ++) {

            nums[i] = suff[i] * pref[i];
        }

        return nums;
        
    }
};
