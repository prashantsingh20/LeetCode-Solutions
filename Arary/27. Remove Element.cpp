/* 27. Remove Element
https://leetcode.com/problems/remove-element/
*/
class Solution {
public:
int removeElement(vector<int>& nums, int val) {
    int count = 0;

    for(int x = 0; x < nums.size(); x++) {
        if(nums[x] != val) {
            nums.insert(nums.begin() + count, nums[x]);
            count++;
            x++;
        }
    }
    return count;
}
};