/* 29. Divide Two Integers
https://leetcode.com/problems/divide-two-integers/
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == (1 << 31) && divisor == -1) return INT_MAX;
        int sign = (dividend>= 0) == (divisor>=0) ? 1 : -1; 
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        int result = 0;
        while((long long)dividend - divisor >= 0){
            int count = 0;
            while((long long)dividend - ((long long)divisor << 1 << count) >= 0) count++;
            result += (long long)1 << count;
            dividend -= (long long)divisor << count;
        }
    
        return (long long) sign*result;
       }
};