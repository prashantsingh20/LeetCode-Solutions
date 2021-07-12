/* 40. Combination Sum II
https://leetcode.com/problems/combination-sum-ii/
*/
class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& candidates, int i, int sum, int target, vector<int>& cur ){
     
        if( sum == target ){
            res.push_back(cur);
            return;
        }
        if( i == candidates.size() ) return;
        
        if( sum + candidates[i] <= target ){
            cur.push_back( candidates[i] );
            solve( candidates, i+1, sum+candidates[i], target, cur );
            cur.pop_back();
        }
        else{
            return;
        }
        for( int x = i; x < candidates.size()-1; ++x){
            if( candidates[x] == candidates[x+1] ){
                i = x+1;
            }
            else
            {
                break;
            }
        }
        solve( candidates, i+1, sum, target, cur );
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ar;
        solve( candidates, 0, 0, target, ar );   
        return res;
    }
};