/* 54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size(),n=matrix[0].size();
        if(m>1 && n==1){
            for(auto i=0;i<m;++i){ res.push_back(matrix[i][0]); }
        }
        for(int lbound=-1,ubound=0,rbound=n,dbound=m;res.size()<m*n;++lbound,++ubound,--rbound,--dbound){
            for(auto r=lbound+1; r<rbound; ++r){
                res.push_back(matrix[ubound][r]);
            }
            for(auto d=ubound+1; d<dbound; ++d){
                res.push_back(matrix[d][rbound-1]);
            }
            if(res.size()==m*n) { break; }
            for(auto l=rbound-2; l>lbound;--l){
                res.push_back(matrix[dbound-1][l]);
            }
            for(auto u=dbound-2; u>ubound; --u){
                res.push_back(matrix[u][lbound+1]);
            }
        }
        return res;
    }
};