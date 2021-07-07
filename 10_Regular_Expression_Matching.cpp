/* 10. Regular Expression Matching
https://leetcode.com/problems/regular-expression-matching/
*/
class Solution {
private:
    vector<vector<char>> memo;
    bool regexMatch(int i, int j, string s, string p){
        if(memo.at(i).at(j) != '*')
            return memo.at(i).at(j) == '1';
        
        bool answer = false;
        if(j == p.length()) answer = i == s.length();
        else{
            bool firstMatch = (i < s.length() && (p.at(j) == s.at(i) || p.at(j) == '.'));
            
            if(j + 1 < p.length() && p.at(j + 1) == '*')
                answer = (regexMatch(i, j + 2, s, p) || firstMatch && regexMatch(i + 1, j, s, p));
            
            else answer = firstMatch && regexMatch(i + 1, j + 1, s, p);
        }
        
        memo.at(i).at(j) = answer ? '1' : '0';
        return answer;        
    }
    
public:
    bool isMatch(string s, string p) {
        memo = vector(s.length() + 1, vector<char>(p.length() + 1, '*'));
        
        return regexMatch(0, 0, s, p);
    }
};