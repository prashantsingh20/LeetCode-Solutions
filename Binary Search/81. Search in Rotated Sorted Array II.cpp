//81. Search in Rotated Sorted Array II
//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
   bool search(vector<int>& nums, int target) {
        
        int low=0,high=nums.size()-1,ans=-1;
        
        
        while(low<=high){
            int mid = low+ (high-low)/2;
            if(nums[mid]==target) return true;
            
            // when both are same then reduce the search space
           
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                continue;
            }
            
             // this line checks if left part is sorted or not
            
            if(nums[low]<=nums[mid] ){
                
            if(target>=nums[low] && target<=nums[mid] )
               high=mid-1;
                
             else low=mid+1;   
                
                // the element is in the unsorted part
                
                
            }
            
            // now we know right part is sorted
            else{
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;
                } // the element is between the middle and end of the sorted part
                
                else{
                    high=mid-1;
                }
                
                // the element is in the unsorted part
            }
    
        }
        
        return false;
    }
};