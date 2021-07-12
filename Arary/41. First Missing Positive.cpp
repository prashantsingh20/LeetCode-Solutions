/* 41. First Missing Positive
https://leetcode.com/problems/first-missing-positive/
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> v(nums.size()+1,0);
        for(int i=0;i<nums.size();i++) {
            if(nums[i]<0||nums[i]>=v.size()) continue;
            v[nums[i]]=1;
        }
        for(int i=1;i<v.size();i++) if(!v[i]) return i;
        return v.size();
    }
};