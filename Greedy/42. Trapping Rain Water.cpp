/* 42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/
*/
class Solution {
public:
	int trap(vector<int>& height) {
		if(height.size()==0){
			return 0;
		}
		int siz=height.size();
		int left_max[siz];
		int right_max[siz];
		int max=INT_MIN;
		int rmax=INT_MIN;
		int sum=0;
		for(int i=0;i<height.size();i++){
			if(max<height[i]){
				max=height[i];
				left_max[i]=max;
			}
			else{
				left_max[i]=max;
			}
		}
		for(int i=height.size()-1;i>=0;i--){
			if(rmax<height[i]){
				rmax=height[i];
				right_max[i]=rmax;
			}
			else{
				right_max[i]=rmax;
			}
		}
		for(int n=0;n<height.size();n++){
			sum=sum+(min(left_max[n],right_max[n])-height[n]);
		}
		return sum;
	}
};