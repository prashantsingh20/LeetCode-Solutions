/*16. 3Sum Closest
https://leetcode.com/problems/3sum-closest/
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        int t=INT_MAX;
        int ans=target;
        for(int i=0;i<sz;i++)
        {
            int l=i+1;
            int r=sz-1;
            int sum=nums[i];
            while(l<r)
            {
                int tmp=nums[i]+nums[l]+nums[r];
                int k=abs(tmp-target);
                if(k<t)
                {
                    t=k;
                    ans=tmp;
                }
                if(tmp>target)
                    r--;
                else if(tmp<target)
                    l++;
                else return target;
            }
        }
        return ans;
    }
};