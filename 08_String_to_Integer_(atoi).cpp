/* 8. String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/
*/
class Solution {
public:
    int myAtoi(string s) {
        int num = 0, sign = 1, digit = 0;
        for(int i=0; i < s.size(); i++) {
            if(s[i] != ' ') {
                if(s[i] == '+' || s[i] == '-')
                    sign = s[i++] == '+' ? 1: -1;
                for(int j = i; j < s.size(); j++) {
                    if(!isdigit(s[j])) return sign * num;
                    digit = s[j] - '0';
                    if(num > (INT_MAX-digit)/10) return sign > 0 ? INT_MAX : INT_MIN;
                    num = 10*num + digit;
                }
                return sign * num;
            }
        }
        return sign * num;
    }
};