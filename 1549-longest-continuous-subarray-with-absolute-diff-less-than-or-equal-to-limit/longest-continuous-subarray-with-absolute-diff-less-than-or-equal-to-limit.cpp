#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    // Function to calculate the length of the longest subarray with the absolute difference 
    // between any two elements not exceeding `limit`.
    int longestSubarray(vector<int>& nums, int limit) {
        // Initialize a multiset to maintain the elements in the current sliding window.
        multiset<int> window_elements; 
        int longest_subarray_length = 0; // Variable to keep track of the max subarray length.
        int window_start = 0; // Starting index of the sliding window.

        // Iterate over the array using `i` as the end of the sliding window.
        for (int window_end = 0; window_end < nums.size(); ++window_end) {
            // Insert the current element into the multiset.
            window_elements.insert(nums[window_end]);

            // If the difference between the largest and smallest elements in the multiset
            // exceeds the `limit`, shrink the window from the left until the condition is satisfied.
            while (*window_elements.rbegin() - *window_elements.begin() > limit) {
                // Erase the leftmost element from the multiset and shrink the window.
                window_elements.erase(window_elements.find(nums[window_start++]));
            }

            // Calculate the length of the current subarray and update the maximum length.
            int current_subarray_length = window_end - window_start + 1;
            longest_subarray_length = max(longest_subarray_length, current_subarray_length);
        }

        // Return the length of the longest subarray found.
        return longest_subarray_length;
    }
};