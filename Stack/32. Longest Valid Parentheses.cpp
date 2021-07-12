/* 32. Longest Valid Parentheses
https://leetcode.com/problems/longest-valid-parentheses/
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0){
            return 0;
        }
        int n = s.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        int ans = 0;
        for(int i=1; i<n; i++){
            // cout<<i-dp[i-1]-1<<endl;
            if(s[i] == ')'){
                if(s[i-1] == '(' && i>1){
                    dp[i] = dp[i-2] + 2;
                }else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1] == '('){
                    dp[i] = dp[i-1] + 2;
                    if(i-dp[i-1]-2 >= 0){
                        dp[i] += dp[i-dp[i-1]-2];
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};