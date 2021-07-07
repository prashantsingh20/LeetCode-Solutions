/* 26. Remove Duplicates from Sorted Array
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();       
        int index = 1;
        
        int prevNum = nums[0];
        for(int iterate = 1; iterate < nums.size(); iterate++)
        {
            while(nums[iterate] == prevNum)
            {
                iterate++;                
                if(iterate >= nums.size()) return index;
            }
            nums[index++] = nums[iterate];
            prevNum = nums[iterate];
        }
        return index;
    }
};