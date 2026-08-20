class Solution {
private:
    int findDays(vector<int>& wt, int cap) {
        int d = 1, load = 0;
        for (int i = 0; i < wt.size(); i++) {
            if (wt[i] + load > cap) {
                d += 1;
                load = wt[i];
            } else {
                load += wt[i];
            }
        }
        return d;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while (low < high) {
            long long mid = (low + high) / 2;
            int numberOfDays = findDays(weights, mid);

            if (numberOfDays < days) {
                high = mid; 
            } else if (numberOfDays == days) {
                high = mid; 
            } else {
                low = mid + 1;
            }
        } 
        
        return low;
    }
};
