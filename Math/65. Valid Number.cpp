//65. Valid Number
//https://leetcode.com/problems/valid-number/

class Solution {
    enum state {
        invalid, q0, q1, q2, q3, q4, q5, q7, q8, q9
    };
    
private:
    vector<vector<state>> states = {
        {invalid, invalid, invalid, invalid, invalid},
        {q1, invalid, q3, q2, invalid},/*Q0*/
        {invalid, invalid, q3, q2, invalid},/*Q1*/
        {invalid, invalid, q4, invalid, invalid},/*Q2*/
        {invalid, q7, q3, q4, invalid},/*Q3*/
        {invalid, q7, q5, invalid, invalid},/*Q4*/
        {invalid, q7, q5, invalid, invalid},/*Q5*/
        {q9, invalid, q8, invalid, invalid},/*Q7*/
        {invalid, invalid, q8, invalid, invalid},/*Q8*/
        {invalid, invalid, q8, invalid, invalid},/*Q9*/
    };
    
    int getIndex(char c) {
        if(c == '+' || c == '-') return 0;
        else if(c == 'e' || c == 'E') return 1;
        else if(isdigit(c)) return 2;
        else if(c == '.') return 3;
        else return 4;
    }
    
    state getNext(state current, char ch) {
        return states[(int)current][getIndex(ch)];
    }
public:
    bool isNumber(string s) {
        state currentState = q0;
        for(int i = 0; i < s.length(); i++) {
            currentState = getNext(currentState, s[i]);
        }
        
        return currentState == q3 || currentState == q4  || currentState == q5  || currentState == q8;
    }
};