//118. Pascal's Triangle
//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> a={{1}};
        for(int i=1;i<n;++i){
            vector<int> v={1};
            for(int j=1;j<i;++j){
                v.push_back(a[i-1][j-1]+a[i-1][j]);
            }
            v.push_back(1);
            a.push_back(v);
        }
        return a;
    }
};