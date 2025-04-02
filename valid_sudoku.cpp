class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> mpp;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char num = board[i][j];
            if (num == '.') continue;
            
            string row = "row" + to_string(i) + num;
            string col = "col" + to_string(j) + num;
            string bx = "box" + to_string(i / 3) + to_string(j / 3) + num;

            if (mpp.count(row) || mpp.count(col) || mpp.count(bx))
                return false;

            mpp.insert(row);
            mpp.insert(col);
            mpp.insert(bx);
        }
    }
    return true;
}
};
