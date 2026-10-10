class Solution {
private:
    int countAtMost(vector<int>& nums, int maxSum) {
        if (maxSum < 0) return 0;
        int left = 0, right = 0, sum = 0, count = 0, n = nums.size();
        
        while(right < n){
            sum += nums[right];
            while(sum > maxSum){
                sum -= nums[left];
                left++;
            }
            count += (right - left + 1); 
            right++;
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
};