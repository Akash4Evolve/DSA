class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posIndex=0 , NegIndex= 1;
        for(int i = 0; i<n;i++){
            if(nums[i]<0){
                ans[NegIndex]=nums[i];
                NegIndex+=2;
            }else{
                ans[posIndex]=nums[i];
                posIndex+=2;
            }
        }
        return ans;

    }
};