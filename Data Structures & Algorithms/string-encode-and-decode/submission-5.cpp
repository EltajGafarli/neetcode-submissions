class Solution {
   public:
    string encode(vector<string>& strs) {
        string res;

        for (auto s : strs) {
            res += s + "#" + to_string(s.length()) + "#";
        }

        return res;
    }

    vector<string> decode(string s) {

        string r;

        vector<string> res;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '#') {
                if (i == s.length() - 1) {
                    break;
                }
                int j = i + 1;

                bool isTrue = true;

                if (s[j] == '#') {
                    isTrue = false;
                }


                while(s[j] != '#') {
                    if(s[j] >= '0' && s[j] <= '9') {
                        j ++;
                    } else {
                        isTrue = false;
                        break;
                    }
                }

                if(isTrue) {
                    res.push_back(r);
                    r = "";
                    i = j;

                    continue;
                }
            }

            r += s[i];
        }

        return res;
    }
};
