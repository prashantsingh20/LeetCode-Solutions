/* 53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int localsum = 0;
        int maxsum = nums[0];
        for(auto i : nums)
        {
            localsum = localsum + i;
            
            if(localsum > maxsum)
                maxsum = localsum;
            
            if(localsum < 0)
                localsum = 0;
        }
        
        return maxsum;
    }
};