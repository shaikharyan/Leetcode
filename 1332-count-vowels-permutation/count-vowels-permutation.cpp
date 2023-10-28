class Solution {
public:
const int MOD = 1000000007;
    int countVowelPermutation(int n) {
         vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));

    // Initialize the base case
    for (int j = 0; j < 5; j++) {
        dp[1][j] = 1;
    }

    // Fill in the dp array based on the rules
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
        dp[i][3] = (dp[i - 1][2]) % MOD;
        dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
    }

    // Sum up the counts for all vowels to get the total count
    long long total_count = 0;
    for (int j = 0; j < 5; j++) {
        total_count = (total_count + dp[n][j]) % MOD;
    }

    return static_cast<int>(total_count);
    }
};