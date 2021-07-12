/* 5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        
        int start = 0, end = 0;
        
        for(int center = 0; center < s.length(); center++){
            int len1   = paliLen(s, center, center);
            int len2   = paliLen(s, center, center + 1);
            
            int length = max(len1, len2);
            
            if(length  > end - start){
                start  = center - (length - 1) / 2;
                end    = center + (length / 2);
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    int paliLen(string &s, int l, int r){
        while(l >= 0 && r < s.length()){
            if(s.at(l) == s.at(r)) l--, r++;
            else break;
        }
        
        return r - l - 1;
    }
};