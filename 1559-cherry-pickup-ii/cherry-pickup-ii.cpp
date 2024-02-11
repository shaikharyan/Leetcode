class Solution {
public:
     int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // dp array to store the maximum cherries collected by both robots at each position
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        
        // Base case: cherries collected at the last row
        for (int col1 = 0; col1 < cols; ++col1) {
            for (int col2 = 0; col2 < cols; ++col2) {
                dp[rows - 1][col1][col2] = grid[rows - 1][col1] + (col1 != col2 ? grid[rows - 1][col2] : 0);
            }
        }
        
        // Iterate from the second last row to the first row
        for (int row = rows - 2; row >= 0; --row) {
            for (int col1 = 0; col1 < cols; ++col1) {
                for (int col2 = 0; col2 < cols; ++col2) {
                    int cherries = grid[row][col1] + (col1 != col2 ? grid[row][col2] : 0);

                    // Explore all possible moves for both robots
                    int maxCherry = cherries;
                    for (int move1 = -1; move1 <= 1; ++move1) {
                        for (int move2 = -1; move2 <= 1; ++move2) {
                            int newCol1 = col1 + move1;
                            int newCol2 = col2 + move2;

                            if (newCol1 >= 0 && newCol1 < cols && newCol2 >= 0 && newCol2 < cols) {
                                maxCherry = max(maxCherry, cherries + dp[row + 1][newCol1][newCol2]);
                            }
                        }
                    }

                    // Save the result in the dp array
                    dp[row][col1][col2] = maxCherry;
                }
            }
        }

        return dp[0][0][cols - 1];
    }
};