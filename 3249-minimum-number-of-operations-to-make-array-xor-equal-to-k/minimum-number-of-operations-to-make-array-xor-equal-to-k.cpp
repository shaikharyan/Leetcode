class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        int result = 0;
        k ^= xorSum; // XOR of elements with k
        while (k > 0) {
            result += k & 1;
            k >>= 1;
        }
        
        return result;
    }
};