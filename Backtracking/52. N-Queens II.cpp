/* 52. N-Queens II
https://leetcode.com/problems/n-queens-ii/
*/
class Solution {
public:
    int ld[300];
    int rd[300];
    int cc[300];
    int N;
    int ans;
    void recursion(int col){
        if(col >= N){
            ans++;
            return;
        }
        for(int i=0;i<N;i++){
            if(ld[i-col+N-1]!=1 && rd[i+col]!=1 && cc[i]!=1){
                ld[i-col+N-1] = rd[i+col] = cc[i] = 1;
                recursion(col+1);
                ld[i-col+N-1] = rd[i+col] = cc[i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        N=n;
        ans=0;       
        recursion(0);
        return ans;
        
    }
};