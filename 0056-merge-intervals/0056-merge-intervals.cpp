#include <vector>

class Solution {
private:
    // Tail-recursive QuickSort with median-of-three pivot selection
    void quickSort(std::vector<std::vector<int>>& intervals, int low, int high) {
        while (low < high) {
            // Find median of low, mid, high to prevent O(n^2) worst case
            int mid = low + (high - low) / 2;
            if (intervals[mid][0] < intervals[low][0]) std::swap(intervals[mid], intervals[low]);
            if (intervals[high][0] < intervals[low][0]) std::swap(intervals[high], intervals[low]);
            if (intervals[mid][0] < intervals[high][0]) std::swap(intervals[mid], intervals[high]);
            
            // Pivot is now at intervals[high]
            int pivot = intervals[high][0];
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (intervals[j][0] < pivot) {
                    i++;
                    std::swap(intervals[i], intervals[j]);
                }
            }
            std::swap(intervals[i + 1], intervals[high]);
            int pivotIndex = i + 1;

            // Tail call optimization: recurse into the smaller partition
            if (pivotIndex - low < high - pivotIndex) {
                quickSort(intervals, low, pivotIndex - 1);
                low = pivotIndex + 1; // Loop handles the right side
            } else {
                quickSort(intervals, pivotIndex + 1, high);
                high = pivotIndex - 1; // Loop handles the left side
            }
        }
    }

public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;

        // Step 1: In-place custom sort
        quickSort(intervals, 0, n - 1);

        // Step 2: In-place merge using an index pointer
        int mergeIndex = 0;

        for (int i = 1; i < n; i++) {
            // If current interval overlaps with the last merged interval
            if (intervals[i][0] <= intervals[mergeIndex][1]) {
                // Update the end boundary in place
                if (intervals[i][1] > intervals[mergeIndex][1]) {
                    intervals[mergeIndex][1] = intervals[i][1];
                }
            } else {
                // Move pointer forward and copy the non-overlapping interval
                mergeIndex++;
                intervals[mergeIndex] = intervals[i];
            }
        }

        // Step 3: Shrink the original vector to remove remaining duplicate/old slots
        intervals.resize(mergeIndex + 1);
        return intervals;
    }
};
