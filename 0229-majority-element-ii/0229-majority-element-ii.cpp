class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       
        int element1 = 0, element2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for (int pointer = 0; pointer < nums.size(); pointer++) {
            if (nums[pointer] == element1) {
                cnt1++;
            } else if (nums[pointer] == element2) {
                cnt2++;
            } else if (cnt1 == 0) {
                element1 = nums[pointer];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                element2 = nums[pointer];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        int verify_cnt1 = 0;
        int verify_cnt2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == element1) {
                verify_cnt1++;
            } else if (nums[i] == element2) {
                verify_cnt2++;
            }
        }
        vector<int> ans;
        int threshold = nums.size() / 3;

        if (cnt1 > 0 && verify_cnt1 > threshold)
            ans.push_back(element1);
        if (cnt2 > 0 && verify_cnt2 > threshold)
            ans.push_back(element2);

        return ans;
    }
};
