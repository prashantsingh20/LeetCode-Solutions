/* 7. Reverse Integer
https://leetcode.com/problems/reverse-integer/
*/
class Solution {
public:
    int reverse(int x) 
    {
        std::string num = std::to_string(x);
        std::reverse(num.begin(), num.end());
        long result = std::stol(num);
        if(x < 0)
        {
            result *= -1;
        }
        if(result <= INT_MAX && result >= INT_MIN)
        {
            return static_cast<int>(result);
        }
        return 0;
    }
};