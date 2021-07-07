/* 18. 4Sum
https://leetcode.com/problems/4sum/
*/
class Solution {
public:    
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for (int i = 0; i < nums.size(); i++) {
            for ( int j = i + 1; j < nums.size(); j++) {
                int sumTarget = target - nums[i] - nums[j];
                int pointer_one = j + 1;
                int pointer_two = nums.size() - 1;
                
                while (pointer_one < pointer_two) {
                    if (nums[pointer_one] + nums[pointer_two] == sumTarget) {
                        int xp = pointer_one;
                        int yp = pointer_two;
                        res.push_back({nums[i], nums[j], nums[xp], nums[yp]});
                        
                        while (pointer_one < pointer_two && nums[pointer_one] == nums[xp]) 
                            pointer_one++;
                        while (pointer_one < pointer_two && nums[pointer_two] == nums[yp]) 
                            pointer_two--;
                    }
                    else if (nums[pointer_one] + nums[pointer_two] > sumTarget) 
                        pointer_two--;
                    else 
                        pointer_one++;   
                }
                
                while (j + 1 < nums.size() && nums[j + 1] == nums[j]) 
                    j++;
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                    i++;
            }
        }
        
        return res;
    }
};