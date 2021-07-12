/* 11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0; 
        int j = height.size()-1;
        int max_water = 0;
        while(i< j){
           int min_height = min(height[i], height[j]); 
           int width = j-i;
            
           max_water = max(max_water, min_height *width);
            if(height[i] > height[j]){
                j--;
            }else{
                i++;
            }
            
        }
        return max_water;
    }
};