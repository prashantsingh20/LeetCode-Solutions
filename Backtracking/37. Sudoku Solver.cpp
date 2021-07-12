/* 37. Sudoku Solver
https://leetcode.com/problems/sudoku-solver/
*/
class Solution {
public:

bool safe(int i, int j, char c, map<string, bool>& mp, bool erase)
{
    string x = "row" + to_string(i) + " ";
    string y = "col" + to_string(j) + " ";
    string z = "box" + to_string(i / 3) + to_string(j / 3) + " ";
    x.push_back(c), y.push_back(c), z.push_back(c);

    if (erase) {
        mp.erase(x), mp.erase(y), mp.erase(z);
        return 0; }
    
    if (mp.count(x) || mp.count(y) || mp.count(z))  return 0;
    mp[x] = mp[y] = mp[z] = true;

    return 1;
}

bool helper(vector<vector<char> >& board, int row, int col, map<string, bool>& mp)
{

    if (col >= 9)
        row++, col = 0;
    if (row >= 9)
        return 1;
    if (board[row][col] != '.')
        return helper(board, row, col + 1, mp);

    for (char num = '1'; num <= '9'; num++) {
        if (!safe(row, col, num, mp, 0))  continue;
        board[row][col] = num;
        if (helper(board, row, col + 1, mp))  return 1;
        safe(row, col, num, mp, true);
    }
    
    board[row][col] = '.';
    return 0;
}

void solveSudoku(vector<vector<char> >& board)
{
    map<string, bool> mp;
	// Marking existing numbers of Sudoku
    for (int i = 0; i < 9; i++) 
        for (int j = 0; j < 9; j++) 
			  if(board[i][j]!='.')
            safe(i, j, board[i][j], mp, 0);
        
    bool ans = helper(board, 0, 0, mp);
}
};