//76. Minimum Window Substring
//https://leetcode.com/problems/minimum-window-substring/


class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        map<char, int> mp;
        
        for(char &ch : t) {
            mp[ch]++;
        }
        
        int requiredCount = t.length(); //we need this many characters
        int i = 0, j  = 0;
        int minStart  = 0; //keep track of start of the min window
        int minWindow = INT_MAX;
        while(j < n) {
            char ch_j = s[j];
            if(mp[ch_j] > 0)
                requiredCount--;
            
            mp[ch_j]--;
            
			//try to shrink the window as much as you can with all requiredCount in hand
            while(requiredCount == 0) { 
                if(minWindow > j-i+1) {
                    minWindow = j-i+1;
                    minStart  = i;
                }
                
                char ch_i = s[i];
                mp[ch_i]++;
                if(mp[ch_i] > 0) //if any character increased from 0, then we need more characters
                    requiredCount++;
                i++;
            }
            
            j++; //Don't ever forget this :-)
        }
        
        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};