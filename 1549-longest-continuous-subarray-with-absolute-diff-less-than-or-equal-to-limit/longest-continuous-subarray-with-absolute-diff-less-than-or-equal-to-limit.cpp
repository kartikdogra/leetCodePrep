#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    
    int longestSubarray(vector<int>& nums, int limit) {
        
        multiset<int> window_elements; 
        int longest_subarray_length = 0; 
        int window_start = 0;
        for (int window_end = 0; window_end < nums.size(); ++window_end) {
            
            window_elements.insert(nums[window_end]);

            
            while (*window_elements.rbegin() - *window_elements.begin() > limit) {
                
                window_elements.erase(window_elements.find(nums[window_start++]));
            }

            
            int current_subarray_length = window_end - window_start + 1;
            longest_subarray_length = max(longest_subarray_length, current_subarray_length);
        }

        
        return longest_subarray_length;
    }
};