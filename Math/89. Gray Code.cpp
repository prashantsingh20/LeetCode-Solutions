//89. Gray Code
//https://leetcode.com/problems/gray-code/

class Solution {
public:
    
    void solve(int n,vector<string>&res){
        if(n==0){
            res.push_back("");
        }
        else{
            solve(n-1,res);
            vector<string>temp;
            temp=res;
            res.clear();
            for(auto i=temp.begin();i!=temp.end();i++){
                res.push_back("0"+*i);
            }
            for(auto i=temp.rbegin();i!=temp.rend();i++){
                res.push_back("1"+*i);
            }
            temp.clear();
        }
    }
    vector<int> grayCode(int n) {
        vector<string>res;
        solve(n,res);
        vector<int>ans;
        for(auto x:res){
            ans.push_back(stoi(x,0,2));
        }
        return ans;
    }
};