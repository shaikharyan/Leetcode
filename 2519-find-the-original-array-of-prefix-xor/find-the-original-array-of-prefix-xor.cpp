class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        const int n = pref.size();
        vector<int> arr(pref);
        for (int i = 1; i < n; i++) arr[i] = pref[i - 1] ^ pref[i];
        return arr;
    }
};