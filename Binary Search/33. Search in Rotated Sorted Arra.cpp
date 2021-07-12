/* 33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int pivot=0;
        for(int i=1;i<nums.size();i++){
            if(nums.at(i)<nums.at(i-1)){
                pivot=i;
                break;
            }
        }
        
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            
            if(nums.at((mid+pivot)%nums.size())==target){
                return (mid+pivot)%nums.size();
            }
            else if(nums.at((mid+pivot)%nums.size())>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
};