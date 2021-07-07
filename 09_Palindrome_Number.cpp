/* 9. Palindrome Number
https://leetcode.com/problems/palindrome-number/
*/
class Solution {
public: 
    bool isPalindrome(int x) {
    int num = x; 
    unsigned int rev=0;
    while(num>0){
        rev = rev*10+num%10;
        num = num/10;
    }
    if(rev==x)
        return true;
    return false;
}
};