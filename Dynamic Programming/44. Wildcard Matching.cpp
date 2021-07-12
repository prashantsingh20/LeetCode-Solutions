/* 44. Wildcard Matching
https://leetcode.com/problems/wildcard-matching/
*/
class Solution {
public:

    bool solve(string &s, string &p, int i, int j, vector<vector<int> > &dp)
    {
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;
        
        if(dp[i][j]!=-1) 
            return dp[i][j];
        
        if(i==s.size())
        {
            int jj = j;
            while( (j<p.size()) && (p[j] == '*') ) j++;
            dp[i][j] = (j==p.size());
            return dp[i][jj] = dp[i][j];
        }
        
        if((s[i]==p[j]) || (p[j] == '?')) 
            return dp[i][j] = solve(s, p, i+1, j+1, dp);
        if(p[j] == '*')
            return dp[i][j] = (solve(s, p, i, j+1, dp) || solve(s, p, i+1, j, dp) || solve(s, p, i+1, j+1, dp));
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
         vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(s, p, 0, 0, dp);
    }
};