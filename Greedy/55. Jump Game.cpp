/* 55. Jump Game
https://leetcode.com/problems/jump-game/
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        else{
        int max_reached=0;
        for(int i=0;i<nums.size();i++){
            max_reached = std::max(max_reached, nums[i]+i);
            if(i==max_reached&&i!=nums.size()-1) return false;
        }
            return true;
        }
    }
};