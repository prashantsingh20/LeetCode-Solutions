//71. Simplify Path
//https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        stack<string> temp_stack;
        int i = 1;
        int n = path.length();
        while(i < n){
            if(path[i] != '/'){
                int j = i+1;
                while(j < n and path[j] != '/'){
                    j++;
                }
                string temp = path.substr(i, j-i);
                if(temp == ".."){
                    if(!s.empty()) s.pop();
                }
                else if(temp != ".") s.push(temp);
                i = j;
            }
            else{
                int j = i+1;
                while(j < n and path[j] == '/') j++;
                i = j;
            }
        }
        string ans = "";
        while(!s.empty()){
            temp_stack.push(s.top());
            // cout << s.top() << " ";
            s.pop();
        }
        while(!temp_stack.empty()){
            ans = ans + "/" + temp_stack.top();
            temp_stack.pop();
        }
        if(ans == "") ans = ans + "/";
        return ans;
    }
};