//   13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, j = 0;
        int integer[] = { 1 ,  5 , 10 , 50 , 100, 500, 1000};
        char roman[]  = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        
        for(int i = 6; i >= 0; i--){
            while(s[j] == roman[i]) {
                ans += integer[i];
                j++;
            }
            if(j < s.length() - 1 && s[j+1] == roman[i]){
                if(i > 0 && s[j] == roman[i-1]) ans += integer[i] * 4 / 5;
                else if(i > 1 && s[j] == roman[i-2]) ans += integer[i] * 9 / 10;
                j += 2;
            }      
        }
        
        return ans;
    }
};