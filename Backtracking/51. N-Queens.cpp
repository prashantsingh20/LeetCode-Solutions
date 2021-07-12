/* 51. N-Queens
https://leetcode.com/problems/n-queens/
*/
class Solution {
public:
    int ld[300];
    int rd[300];
    int cc[300];
    int N;
    vector<vector<string>> ans;
    void recursion(vector<string> board,int col){
        if(col >= N){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<N;i++){
            if(ld[i-col+N-1]!=1 && rd[i+col]!=1 && cc[i]!=1){
                ld[i-col+N-1] = rd[i+col] = cc[i] = 1;
                board[i][col]='Q';
                recursion(board,col+1);
                board[i][col]='.';
                ld[i-col+N-1] = rd[i+col] = cc[i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        string s;
        for(int i=0;i<n;i++){
            s+=".";
        }
        vector<string> board(n,s);
        for(auto &i:board){
            cout<<i<<endl;
        }
        recursion(board,0);
        return ans;
        
    }
};