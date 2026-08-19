class Solution {
private:
    bool possible(vector<int>& nums, int day, int r, int b) {
        int cnt = 0;
        int noOfb = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= day) {
                cnt++;
            } else {
                noOfb += (cnt / b);
                cnt= 0;
            }
        }
        noOfb += (cnt / b);
        return noOfb >= r;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if (val > bloomDay.size())
            return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};