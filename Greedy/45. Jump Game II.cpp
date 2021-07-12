/* 45. Jump Game II
https://leetcode.com/problems/jump-game-ii/
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
		// initialize the array such that it is impossible to reach;
        vector<int> step(n, INT_MAX); 
        // it takes 0 steps to reach 0th index;
        step[0] = 0;
        for (int i = 0; i < n - 1; i++) {
			 // max index which can be traversed from the index i;
            for (int j = 1; j <= nums[i] && i + j < n; j++)
                step[i + j] = min(step[i + j], step[i] + 1); // we need minimum steps possible ;
        }
        //return the min steps required to reach the last index;
        return step[n - 1];
    }
};