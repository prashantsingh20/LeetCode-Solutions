// 64. Minimum Path Sum
//https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        int sum[M][N];
        sum[0][0] = grid[0][0];
        for (int x = 0; x<M;x++){
            for (int y = 0; y <N;y++){
                if (x==0 && y==0){
                    continue;
                }
                else if(x==0){
                    sum[x][y] = grid[x][y] + sum[x][y-1];
                    continue;
                }
                else if (y==0){
                    sum[x][y] = grid[x][y] + sum[x-1][y];
                    continue;
                }
                else {
                    sum[x][y] = min(sum[x-1][y], sum[x][y-1]) + grid[x][y];
                    
                }     
        }
        }
        return sum[M-1][N-1];
    }
};