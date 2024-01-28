class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<std::vector<int>> output;

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates for the first element
            }

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue; // Skip duplicates for the second element
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = nums[i] + static_cast<long long>(nums[j]) + nums[left] + nums[right];

                    if (sum == target) {
                        output.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;

                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return output;
    }
};