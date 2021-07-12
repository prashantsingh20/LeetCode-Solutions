//63. Unique Paths II
//https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int r=obs.size();
        int c=obs[0].size();
        if(obs[r-1][c-1]) return 0;
        vector<vector<long>> ans(r,vector<long>(c,0));
        ans[r-1][c-1]=1;
        for(int j=c-1;j>=0;j--)
        {
            for(int i=r-1;i>=0;i--)
            {
                if(obs[i][j]==0)
                {
                    if(j+1<c)
                        ans[i][j]+=ans[i][j+1];
                    if(i+1<r)
                        ans[i][j]+=ans[i+1][j];
                   
                }
            }
        }
        return ans[0][0];
    }
};