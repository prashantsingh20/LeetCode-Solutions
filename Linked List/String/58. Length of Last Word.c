/* 58. Length of Last Word
https://leetcode.com/problems/length-of-last-word/ 
*/
public class Solution {
    public int LengthOfLastWord(string s) {
        return s.Trim().Split(' ').LastOrDefault().Length; 
    }
}