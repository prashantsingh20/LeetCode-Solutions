/* 34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ray
*/

class Solution {
public:
    
     int xtreameright(vector<int>&nums,int target,int si,int ei){
        
        if(si>ei){
            return -1;
        }
        
        int mi=si+(ei-si)/2;
        int ans=-1;
        if(nums[mi]==target){
            
            ans=max(mi,xtreameright(nums,target,mi+1,ei));
            return ans;
            
            
        }
        else if(nums[mi] < target){
            
            return xtreameright(nums,target,mi+1,ei);
            
            
        }
        else{
            return xtreameright(nums,target,si,ei-1);
        }
    }
    
    int xtreameleft(vector<int>&nums,int target,int si,int ei){
        
        if(si>ei){
            return INT_MAX;
        }
        
        int mi=si+(ei-si)/2;
        int ans=INT_MAX;
        if(nums[mi]==target){
            
            ans=min(mi,xtreameleft(nums,target,si,mi-1));
            return ans;
            
            
        }
        else if(nums[mi] < target){
            
            return xtreameleft(nums,target,mi+1,ei);
            
            
        }
        else{
            return xtreameleft(nums,target,si,ei-1);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int si=0;
        int ei=nums.size()-1;
        
        int left=-1;
        int right=-1;
        
        vector<int>ans;
        
        while(si <=ei){
            
            int mi=si+(ei-si)/2;
            if(nums[mi]==target){
                
                 left=xtreameleft(nums,target,si,mi-1);
                 right=xtreameright(nums,target,mi+1,ei);
                
                left=min(left,mi);
                right=max(right,mi);
                
                break;
            }
            else if(nums[mi] < target){
                
                si=mi+1;
            }
            else{
                
                ei=mi-1;
                
            }
        }
        
        ans.push_back(left);
        ans.push_back(right);
        
        return ans;
    }
};