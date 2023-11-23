class Solution {
public:
bool isArithmetic(vector<int>& subarray) {
        if (subarray.size() <= 2) {
            return true; // Any subarray with 0 or 1 element is always arithmetic.
        }

        sort(subarray.begin(), subarray.end());

        int commonDifference = subarray[1] - subarray[0];

        for (int i = 2; i < subarray.size(); ++i) {
            if (subarray[i] - subarray[i - 1] != commonDifference) {
                return false;
            }
        }

        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
            vector<bool> result;

        for (int i = 0; i < l.size(); ++i) {
            int left = l[i], right = r[i];
            vector<int> subarray(nums.begin() + left, nums.begin() + right + 1);

            result.push_back(isArithmetic(subarray));
        }

        return result;
    }
};