//80. Remove Duplicates from Sorted Array II
//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
        int slow=2,fast=2;
        while(fast<n){
            if(nums[slow-2]!=nums[fast]) nums[slow++]=nums[fast];
            fast++;
        }
        return slow;
    }
};