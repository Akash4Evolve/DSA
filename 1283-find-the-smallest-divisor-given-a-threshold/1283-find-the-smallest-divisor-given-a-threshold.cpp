class Solution {
private:
   
    int getSumAfterDivision(const vector<int>& nums, int divisor) {
        int totalSum = 0;
        for (int num : nums) {
           
            totalSum += (num + divisor - 1) / divisor; 
        }
        return totalSum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = 0;
        
        
        for (int num : nums) {
            high = max(high, num);
        }
        
        int result = high;
        
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (getSumAfterDivision(nums, mid) <= threshold) {
                result = mid;     
                high = mid - 1;    
            } else {
                low = mid + 1;  
            }
        }
        
        return result;
    }
};
