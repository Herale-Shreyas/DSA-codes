class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        int i=0, j=0, count = 0;
        
        while(j < n) {
            if(nums[j] == 1) j++;
            else {
                if(k > 0) {
                    j++;
                    k--;
                }
                else {
                    while(nums[i] == 1) {
                        i++;
                    }

                    // i++ will ensure that the new sliding window is taken care of(the same as i=0 and j=0)
                    // similar to start position and then calculating new answers from scratch
                    i++;
                    k++;
                }
            }
            count = max(count, j-i);
        }
        return count;
    }
};
