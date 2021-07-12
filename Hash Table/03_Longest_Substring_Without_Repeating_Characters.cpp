/* 3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return 1;
        int max=0;
        int i=0,j,start,end;
        for(j=1;j<s.size();j++){
            start=i;
            end=j;
            while(start<end){
                if(s[start]==s[end]){
                    i=start+1;
                    break;
                }
                start++;
            }
             max = max>(end-i)+1?max:(end-i)+1;
        }
        return max;
    }
};