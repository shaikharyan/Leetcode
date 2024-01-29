class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
          int n = 9;

        // Use hash tables for rows, columns, and sub-boxes
        unordered_set<char> rowSet[n], colSet[n], subBoxSet[n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char curr = board[i][j];
                if (curr == '.') continue;

                // Check row
                if (!rowSet[i].insert(curr).second) return false;

                // Check column
                if (!colSet[j].insert(curr).second) return false;

                // Check sub-box
                int subBoxIndex = (i / 3) * 3 + j / 3;
                if (!subBoxSet[subBoxIndex].insert(curr).second) return false;
            }
        }

        return true;
    }
};