class Solution {
private:
    // Helper function to check if Koko can finish all bananas at 'speed' within 'h' hours
    bool canEatAll(const std::vector<int>& piles, int h, int speed) {
        long long hoursSpent = 0; // Use long long to prevent integer overflow during accumulation
        
        for (int pile : piles) {
            hoursSpent += (pile + speed - 1) / speed; 
            
            // Optimization: If hours exceed limit early, terminate to save time
            if (hoursSpent > h) {
                return false;
            }
        }
        return hoursSpent <= h;
    }

public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // The minimum possible speed is 1 banana per hour
        int low = 1; 
        
        // The maximum effective speed is the size of the largest pile
        int high = *std::max_element(piles.begin(), piles.end()); 
        int ans = high;

        // Binary search on the answer space
        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevents overflow compared to (low + high) / 2

            if (canEatAll(piles, h, mid)) {
                ans = mid;       // 'mid' works, record it as a potential answer
                high = mid - 1;  // Try to find a smaller valid speed to minimize it
            } else {
                low = mid + 1;   // 'mid' is too slow, we must increase the speed
            }
        }
        return ans;
    }
};
