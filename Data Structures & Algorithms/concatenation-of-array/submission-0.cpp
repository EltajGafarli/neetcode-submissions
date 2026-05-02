class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();

        nums.resize(2 * size);

        for(int i = 0; i < size; i ++) {
            nums[size + i] = nums[i];   
        }

        return nums;
    }
};