class Solution {
public:
    // Helper function to count subarrays with at most k odd numbers
    int numberOfSubarraysAtMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0, cnt = 0, oddCount = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] % 2 == 1) {
                oddCount++;
            }
            while (oddCount > k) {
                if (nums[l] % 2 == 1) {
                    oddCount--;
                }
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // Number of subarrays with exactly k odd numbers = 
        // number with at most k - number with at most (k - 1)
        return numberOfSubarraysAtMost(nums, k) - numberOfSubarraysAtMost(nums, k - 1);
    }
};