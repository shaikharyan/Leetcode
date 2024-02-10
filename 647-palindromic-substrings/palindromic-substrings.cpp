class Solution {
public:
    int countPalindrome(int j, int k, string &s)
    {
        int ans = 0;
        while(j> -1 && k < s.length() && s[j] == s[k])
            {
                ans++;
                j--;
                k++;
            }
            return ans;

    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i< s.length();i++)
        {
            ans += countPalindrome(i,i,s)+countPalindrome(i,i+1,s);
            
        }
        return ans;
    }
};