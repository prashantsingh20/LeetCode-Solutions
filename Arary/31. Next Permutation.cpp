/* 31. Next Permutation
https://leetcode.com/problems/next-permutation/
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
	    int n = nums.size();
        for (int j=n-2; j>=0; --j) {
            if (nums[j] < nums[j+1]) {
                auto it = upper_bound(nums.rbegin(), nums.rbegin()+n-j-1, nums[j]);
                int i = nums.rend() - it - 1;
                swap(nums[i], nums[j]);
                reverse(nums.begin() + j+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};