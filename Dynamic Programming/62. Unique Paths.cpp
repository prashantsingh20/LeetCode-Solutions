/* 62. Unique Paths
https://leetcode.com/problems/unique-paths/
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = m-1;
        int b = n-1;
        int i, j;
        long long res=1;
        
        if(a>b) 
            j = b;
        else
            j = a;
        
        for(i=0 ; i<j ; i++) {
            res *= a+b-i;
            res /= (i+1);
        } 
        
        return res;
    }
};