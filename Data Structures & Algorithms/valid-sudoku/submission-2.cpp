class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int size = board.size();

        set<string> seen;

        for(int i = 0; i < size; i ++) {
            for(int j = 0; j < size; j ++) {
                if (board[i][j] == '.') continue;

                char val = board[i][j];

                string row = "r" + to_string(i) + "-" + val;
                string col = "c" + to_string(j) + "-" + val;
                string b = "b" + to_string(i / 3) + to_string(j / 3) + "-" + val;

                if (seen.count(row) || seen.count(col) || seen.count(b)) {
                    return false;
                }

                seen.insert(row);
                seen.insert(col);
                seen.insert(b);
            }
        }

        return true;
    }
};