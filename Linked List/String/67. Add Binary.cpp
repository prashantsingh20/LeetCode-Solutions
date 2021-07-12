//67. Add Binary
//https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i=a.length()-1, j=b.length()-1;
        string res;
        while(i>=0 || j>=0 || carry){
            int tmp=0;
            if(i>=0){
                tmp += a[i]-'0';
                i--;
            }
            if(j>=0){
                tmp += b[j]-'0';
                j--;
            }
            tmp += carry;
            if(tmp==1){
                carry = 0;
                tmp = 1;
            }
            else if(tmp==2){
                carry = 1;
                tmp = 0;
            }
            else if(tmp==3){
                carry = 1;
                tmp = 1;
            }
            res += char(tmp)+'0';
        }
        for(int i=0; i<(res.length())/2; i++){
            char tmp=res[i];
            res[i]=res[res.length()-1-i];
            res[res.length()-1-i]=tmp;
        }
        return res;
        
    }
};