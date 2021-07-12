/* 48. Rotate Image
https://leetcode.com/problems/rotate-image/
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz= matrix.size();
        vector<vector<int>> ex_matrix;
        for(int i=0; i<sz; ++i) {
            ex_matrix.push_back(matrix[i]);
        }
        for(int i=0, k=sz-1; i<sz ; ++i, --k) {
            for(int j=0; j<sz; ++j) matrix[j][k]=ex_matrix[i][j];
        }
    }
};