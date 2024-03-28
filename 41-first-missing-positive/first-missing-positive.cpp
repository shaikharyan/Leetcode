class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // for(int i = 0; i < n; ++ i)
        //     while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
        //         swap(A[i], A[A[i] - 1]);
        
        // for(int i = 0; i < n; ++ i)
        //     if(A[i] != i + 1)
        //         return i + 1;
        
        // return n + 1;

         int n = nums.size();

        // Remove negative and numbers greater than N, those are unwanted.
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0 || nums[i] > n) nums[i] = 0;
        }

        // Starting from index 0, we will start marking.
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 || nums[i] == -1) continue;

            int index = nums[i] - 1; // index is the position of number which needs to be updated
            nums[i] = 0; 
            int temp;
            while (nums[index] > 0) {
                temp = nums[index];
                nums[index] = -1;
                index = temp - 1;
            }
            nums[index] = -1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) return i + 1;
        }
        return n + 1;

    }
};