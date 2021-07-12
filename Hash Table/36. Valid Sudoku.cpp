/* 36. Valid Sudoku
https://leetcode.com/problems/valid-sudoku/
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        bool t1;
        bool t2;
        bool t3;
        for(int k=0;k<9;k++)
        {
            unordered_map<char,bool> temp;
            t1=checkRow(0,9,k,board,temp);
            if(!t1)
            {
                return false;
            }
        }
        for(int l=0;l<9;l++)
        {
            unordered_map<char,bool> temp;
            t2=checkColumn(0,9,l,board,temp);
            if(!t2)
            {
                return false;
            }
        }
        for(int i=0;i<m;i=i+3)
        {
            for(int j=0;j<n;j=j+3)
            {
                unordered_map<char,bool> temp;
                t3=tcheck(i,j,board,temp);
                if(!t3)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkColumn(int i,int j,int a,vector<vector<char>>& board,unordered_map<char,bool> temp)
    {
        for(int k=i;k<j;k++)
        {
            if(board[a][k]=='.')
            {
                continue;
            }
            else if(temp[board[a][k]])
            {
                return false;
            }
            else
            {
                temp[board[a][k]]=true;
            }
        }
        return true;
    }
    bool checkRow(int i,int j,int a,vector<vector<char>>& board,unordered_map<char,bool> temp)
    {
        for(int k=i;k<j;k++)
        {
            if(board[k][a]=='.')
            {
                continue;
            }
            else if(temp[board[k][a]])
            {
                return false;
            }
            else
            {
                temp[board[k][a]]=true;
            }
        }
        return true;
    }
    bool tcheck(int a,int b,vector<vector<char>>& board,unordered_map<char,bool> temp)
    {
        for(int k=a;k<a+3;k++)
        {
            for(int l=b;l<b+3;l++)
            {
                if(board[k][l]=='.')
                {
                continue;
                }
                else if(temp[board[k][l]])
                {
                    return false;
                }
                else
                {
                    temp[board[k][l]]=true;
                }
            }
        }
        return true;
    }
};