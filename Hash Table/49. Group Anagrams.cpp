/* 49. Group Anagrams
https://leetcode.com/problems/group-anagrams/
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> mpp;
        for(string str:strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            mpp[s].push_back(str);
        }
        for(auto const& it : mpp)
        {
            answer.push_back(it.second);
        }
        return answer;
    }
};