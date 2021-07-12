/* 17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
class Solution {
public:
    void possible(string A,int index,vector<string> &arr,unordered_map<char,string> &m,string s)
{
    if(index==A.length())
    {
        arr.push_back(s);
        return;
    }
    for(int i=0;i<m[A[index]].length();i++)
    {
        possible(A,index+1,arr,m,s+m[A[index]][i]);
    }
}
    vector<string> letterCombinations(string A) {
         unordered_map<char,string> m;
    // m['0'] = "0";
    // m['1'] = "1";
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    vector<string> arr;
    if(A!="")
    {
        possible(A,0,arr,m,"");
    } 
    return arr;
    }
};