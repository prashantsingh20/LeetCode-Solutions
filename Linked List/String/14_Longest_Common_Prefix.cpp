// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        
        for(auto i=1;i<strs.size();i++)
        {
            string s=strs[i];
            for(auto j=0;j<ans.length();j++)
            {
                if(j<s.length() && ans[j]==s[j])
                    continue;
                else 
                    ans=ans.substr(0,j);
                    
            }
        }
        
        return ans;
        
    }
};