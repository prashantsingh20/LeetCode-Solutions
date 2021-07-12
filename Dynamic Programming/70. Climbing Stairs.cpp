//70. Climbing Stairs
//https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
   int climbStairs(int n) {
    if(n <= 2)
        return n;
	//base case
    int first = 1;
    int second = 2;
	//stores the current value while looping
    int result;
    
    for(int i = 3; i <= n; i++){
		//set the current value equal to sum of two previous values
        result = (first + second);
		//reset the previous values.
        first = second;
        second = result;
    }
    return result;
}
};