class Solution {
public:
    int reductionOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
        
        int operations = 0;
        int currentMax = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < currentMax) {
                operations += i;
                currentMax = nums[i];
            }
        }

        return operations;
    }
};