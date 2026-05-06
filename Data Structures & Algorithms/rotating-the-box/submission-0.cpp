class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int size = boxGrid.size();
        int rowSize = boxGrid[0].size();
        vector<vector<pair<int, char>>> pairs;


        for(int i = 0; i < boxGrid.size(); i ++) {
            int j = 0;

            int rowSize = boxGrid[i].size();

            int dotCount = 0;

            int dyz = 0;

            vector<pair<int, char>> v;


            while(j < rowSize) {

                if (boxGrid[i][j] == '.') {
                    dotCount ++;
                }
                
                if (boxGrid[i][j] == '*') {
                       v.push_back(make_pair(dotCount, '.'));
                       v.push_back(make_pair(dyz, '#'));
                       v.push_back(make_pair(-1, '*'));

                       dotCount = 0;
                       dyz = 0;

                }

                if (boxGrid[i][j] == '#') {
                    dyz ++;
                }

                j ++;
            }

            if (dotCount != 0) {
                v.push_back(make_pair(dotCount, '.'));
            }

            if (dyz != 0) {
                v.push_back(make_pair(dyz, '#'));
            }

            pairs.push_back(v);
        }

        for(int i = 0; i < size; i ++) {
            auto v = pairs[i];

            int j = 0;

            for(auto p: v) {
                auto f = p.first;
                auto s = p.second;

                if (s == '*') {
                    j ++;
                } else if (s == '#') {

                    while(f -- > 0) {
                        boxGrid[i][j] = '#';
                        j ++;
                    }
                } else {
                    while(f -- > 0) {
                        boxGrid[i][j] = '.';
                        j ++;
                    }
                }
            }
        }

        vector<vector<char>> res;

        for(int i = 0; i < rowSize; i++) {
            vector<char>v;
            for(int j = 0; j < size; j ++) {
                v.push_back(boxGrid[size - j - 1][i]);
            }

            res.push_back(v);
        }

        return res;
        
    }
};