class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans; // A 4-sum requires at least 4 elements

        sort(nums.begin(), nums.end());

        // First anchor pointer
        for (int h = 0; h < n - 3; h++) {
            if (h > 0 && nums[h] == nums[h - 1]) continue; // Skip duplicate h

            // Second anchor pointer (Your original 3Sum outer loop)
            for (int i = h + 1; i < n - 2; i++) {
                if (i > h + 1 && nums[i] == nums[i - 1]) continue; // Skip duplicate i

                int j = i + 1, k = n - 1;
                while (j < k) {
                    // Use long long to prevent integer overflow during addition
                    long long sum = (long long)nums[h] + nums[i] + nums[j] + nums[k];

                    if (sum < target) {
                        j++;
                    } else if (sum > target) {
                        k--;
                    } else {
                        ans.push_back({nums[h], nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1]) j++; // Skip duplicate j
                        while (j < k && nums[k] == nums[k + 1]) k--; // Skip duplicate k
                    }
                }
            }
        }
        return ans;
    }
};
