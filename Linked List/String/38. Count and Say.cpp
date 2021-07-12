/* 38. Count and Say
https://leetcode.com/problems/count-and-say/
*/
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        if(n==1)return ans;
        for(int j=2;j<=n;j++){
            char ch = ans[0];
            char cnt = '0';
            string answer_in_array;
            for(int i=0;i<ans.size();i++){
                if(ch == ans[i]){
                    cnt = cnt + 1;
                }
                else{
                    answer_in_array.push_back(cnt);
                    answer_in_array.push_back(ch);
                    ch = ans[i];
                    cnt = '1';
                }
            }
            answer_in_array.push_back(cnt);
            answer_in_array.push_back(ch);
            ans = "";
            ans = answer_in_array;
        }
        return ans;
    }
};
