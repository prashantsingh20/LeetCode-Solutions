/* 22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/
*/
class Solution {
    private:
    vector<string> valid;
    void generate (string &s, int open, int close){
        //base condition
        if(open==0 && close== 0){
            valid.push_back(s);
            return ;
        }
        // when to insert open paranthesis
        if(open>0){
            s.push_back('(');
            generate(s,open-1 ,close);
            s.pop_back();
        }
        //when to insert closed paranthesis
        if(close>0 && close>open){
            s.push_back(')');
            generate(s,open,close-1);
            s.pop_back();
        }    
        
    }
    public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s,n,n);
        return valid;
    }
};