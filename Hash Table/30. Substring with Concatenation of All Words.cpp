/* 30. Substring with Concatenation of All Words
https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].length();
        int total = wordLength*words.size();
        unordered_map<string,int> m;
        vector<int> v;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        for(int i=0;i<s.length()-total+1;i++)
        {
            unordered_map<string,int> temp;
            int count =0;
            for(int j=i;j<total+i;j+=wordLength)
            {
                string t = s.substr(j,wordLength);
                temp[t]++;
                if(temp[t]<=m[t]&&m[t]!=0)
                {
                    count++;
                }
                else
                {
                    count =0;
                    break;
                }
            }
            if(count==words.size())
            {
                v.push_back(i);
            }
        }
        return v;
    }
};
