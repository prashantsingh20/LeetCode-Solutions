//119. Pascal's Triangle II
//https://leetcode.com/problems/pascals-triangle-ii/
class Solution
{
public:
    int binomial(int n,int i)
    {
        if(i==0||i==n)
        {
            return 1;
        }
        if(i>n-i)
        {
            i=n-i;
        }
        long long ans=1;
        for(int j=0;j<i;j++)
        {
            ans=ans*(n-j);
            ans=ans/(j+1);
        }
        return ans;
    }
    vector<int> getRow(int n)
    {
        vector<int>v;
        for(int i=0;i<=n;i++)
        {
            int res=binomial(n,i);
            v.push_back(res);
        }
        return v;
    }
};