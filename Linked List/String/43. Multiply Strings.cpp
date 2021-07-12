/* 43. Multiply Strings
https://leetcode.com/problems/multiply-strings/
*/
class Solution {
public:
    string add(string num1, string num2){
        int sum =0;
        int carry =0;
        int i=num1.length()-1;
        int j=num2.length()-1;
        string temp="";
        while(i>=0 || j>=0){
            int n1 = (i>=0)? num1[i]-'0':0;
            int n2 = (j>=0)? num2[j]-'0':0;
            
            sum = n1+n2+carry;
            carry = sum/10;
            sum=sum%10;
            char ch = '0'+sum;
            temp=ch+temp;
            i--;j--;
        }
        if(carry>0)
            temp = to_string(carry)+temp;
        return temp;
    }
    vector<string>mul(string num1, string num2){
        int count=0;
        vector<string>res;
        
        for(int i=num1.length()-1;i>=0;i--){
            int n1 = num1[i]-'0';
            int carry = 0;string temp="";
            for(int j=num2.length()-1;j>=0;j--){
                int n2 = num2[j]-'0';
                int product = n1*n2;
                product = product+carry;
                carry = product/10;
                product=product%10;
                char ch = '0'+product;
                temp=ch+temp;
            }
            if(carry>0)
                temp=to_string(carry)+temp;
            for(int iter=0;iter<count;iter++)
                temp=temp+'0';
            count++;
            
            res.push_back(temp);
        }
        return res;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        vector<string>numbers=mul(num1,num2);
        string res=numbers[0];
        for(int i=1;i<numbers.size();i++){
            res = add(res,numbers[i]);
        }
        return res;
    }
};