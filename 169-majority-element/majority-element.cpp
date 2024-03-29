class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n/2];
          int count = 0;    
        int element = 0; 

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                element = nums[i];
                count = 1;
            } else if (element == nums[i]) {
                count++;
            } else {
                count--;
            }
        }

        return element; 
    }
};