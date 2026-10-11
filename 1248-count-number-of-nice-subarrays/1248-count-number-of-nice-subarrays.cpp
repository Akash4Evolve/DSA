class Solution {
    private:
    int mostAt(vector<int>&nums , int k){
         int n = nums.size();
        int left = 0 , right = 0 , count = 0 , sum = 0;
        while(right<n){
            sum += (nums[right]%2);
            while(sum>k){
                sum-=(nums[left]%2);
                left++;
            }
            count=count+(right-left+1);
            right++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       return mostAt(nums,k) - mostAt(nums,k-1);
    }
};