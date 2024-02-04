class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i]))
            {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if(abs(i-mp[nums[i]])<=k)
                    return true;
            }
           
            mp[nums[i]] = i;
        }
        
        return false;
    }
};