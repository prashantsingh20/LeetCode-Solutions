/* 59. Spiral Matrix II
https://leetcode.com/problems/spiral-matrix-ii/
*/
public class Solution {
    public int[][] GenerateMatrix(int n) {
        var res = new int[n][];
        for(int i = 0; i < n; i++)
            res[i] = new int[n];
        
        int top = 0, bottom = n - 1, left = 0, right = n -1;
        int dir = 0; // 0: l->r, 1: t->b, 2: r->l, 3: b->t 
        int count = 1;
        while(count <= n*n){
            if(dir == 0){
                for(int j = left; j <= right; j++){
                    res[top][j] = count;
                    count++;
                }
                top++;
            }
            if(dir == 1){
                 for(int i = top; i <= bottom; i++){
                    res[i][right] = count;
                    count++;
                }
                right--;
            }
            if(dir == 2){
                for(int j = right; j >= left; j--){
                    res[bottom][j] = count;
                    count++;
                }
                bottom--;
            }
            if(dir == 3){
                for(int i = bottom; i >= top; i--){
                    res[i][left++] = count;
                    count++;
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }
}