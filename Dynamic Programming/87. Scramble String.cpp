//87. Scramble String
//https://leetcode.com/problems/scramble-string/

class Solution {
public:
    bool isScramble(string s1, string s2) {    
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 != n2) return false;
        
        int n =s1.length();
        vector<vector<vector<bool>>> dp (n,(vector<vector<bool>>(n,vector<bool>(n+1,false))));
        
        for(int len = 1; len <= n ; len++){
            for(int i = 0 ; i<=n-len ;i++){
                for(int j = 0 ; j<=n-len ;j++){
                    if(len == 1 && s1[i] == s2[j])
                        dp[i][j][len] = true;
                    else 
                        for(int k = 1 ; k<len && !dp[i][j][len]; k++){
                            dp[i][j][len] = ( dp[i][j][k] &&  dp[i+k][j+k][len-k])||( dp[i][j+len-k][k] &&  dp[i+k][j][len-k]);
                        }
                 }
            }
        }
        
       return  dp[0][0][n]; 
    }
};
