class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int size = nums.size(); 
        vector<int> flips(size + 1, 0); 
        int result = 0; 
        int flipCount = 0; 

        
        for (int i = 0; i < size; ++i) {
            flipCount += flips[i]; 
            if (flipCount % 2 == nums[i]) {
                
                if (i + k > size) {
                    return -1;
                }
                
                flips[i] += 1;     
                flips[i + k] -= 1; 
              
                
                flipCount++;
                result++;
            }
        }
      
        
        return result;
    }
};