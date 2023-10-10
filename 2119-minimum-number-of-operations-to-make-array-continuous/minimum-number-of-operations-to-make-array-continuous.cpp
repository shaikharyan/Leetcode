class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans=INT_MAX;
        sort(nums.begin(), nums.end());
        nums.erase(unique(begin(nums),end(nums)),end(nums));
        int end = 0;
        for(int start=0,end=0; start<nums.size(); ++start)
        {
            while (end < nums.size() && nums[end] < nums[start] + n) 
            {
                ans=min(ans,n-(++end -start));
            }
        }

        return ans;
    }
};


Approach
Sorting and Removing Duplicates:
First, the code sorts the input array nums in ascending order. This is done to make it easier to find the maximum and minimum elements.
It also removes any duplicate elements, ensuring that all elements are unique. This addresses the first condition.

Sliding Window Approach:
The core of the code is a sliding window approach, where the code iterates through potential "start" elements and extends a "window" to find a valid continuous subarray.
For each potential "start" element, it uses a while loop to find the maximum possible "end" element such that the difference between nums[end] and nums[start] is less than n (the length of the array).

Calculating Operations:
Once the valid subarray is found, the code calculates the number of operations needed to make it continuous.
The number of operations is calculated as n - (end - start + 1). This formula considers the length of the array and the size of the valid subarray.

Tracking Minimum Operations:
The code keeps track of the minimum operations found so far using the ans variable.
For each potential "start" element, it updates ans with the minimum of the current ans and the calculated operations.

Final Result:
After iterating through all potential "start" elements, the code returns the final value of ans, which represents the minimum number of operations needed to make the entire array continuous.

Complexity
Time complexity:
o(n*log(n))

Space complexity:
