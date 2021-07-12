/*39. Combination Sum
https://leetcode.com/problems/combination-sum/
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int s = candidates.size();
        vector<int> v;
        solve(candidates,s,v,target);
        return res;
    }
    void solve(vector<int>& candidates,int s,vector<int>& v,int target) {
        if(s == 0)
            return;
        if(target == 0) {
            res.push_back(v);
            return;
        }
        if(candidates[s-1] <= target) {
            v.push_back(candidates[s-1]);
            solve(candidates,s,v,target-candidates[s-1]);
            v.pop_back();
        }
        solve(candidates,s-1,v,target);
    }
};