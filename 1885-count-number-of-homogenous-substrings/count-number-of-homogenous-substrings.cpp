class Solution {
public:
    int countHomogenous(string s) {
       const int MOD = 1e9 + 7;
        long long count = 0; // To handle large results

        char currentChar = ' ';
        int currentCount = 0;

        for (char c : s) {
            if (c == currentChar) {
                currentCount++;
            } else {
                currentChar = c;
                currentCount = 1;
            }

            count = (count + currentCount) % MOD;
        }

        return static_cast<int>(count);
    }
};