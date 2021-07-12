/* 50. Pow(x, n)
https://leetcode.com/problems/powx-n/
*/
class Solution 
{
public:
    double myPow(double b, int power) 
    {
        double res = 1.0;
        long long p = power;
        if (p < 0) {
            p = -p;
        }
        
        while (p > 0) {
            if ((p & 1) == 1) {
                res = res * b;
                p = p - 1;
            }
            else {
                b = b * b;
                p = p >> 1;
            }
        }
        
        if (power < 0)      
            return double(1.0 / res);
        else                
            return res;
    }
};