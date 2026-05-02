class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        int size = arr.size() - 1;

        vector<int> pref(size + 1);

        pref[size] = -1;


        for(int i = size; i >= 1; i --) {
            pref[i - 1] = max(pref[i], arr[i]);
        }

        arr[size] = -1;

        for(int i = 0; i < pref.size(); i ++) {
            arr[i] = pref[i];
        }

        return arr;
    }
};