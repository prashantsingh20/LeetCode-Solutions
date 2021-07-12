//128. Longest Consecutive Sequence
//https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxSeq=0, range_left, range_right;
        unordered_map<int, pair<int, int>> _map;
        for(auto num : nums)
        {
            if(_map.find(num)!=_map.end()) continue;
            auto entry_left=_map.find(num-1);
            auto entry_right=_map.find(num+1);
            range_left=(entry_left!=_map.end()) ? entry_left->second.first : num;
            range_right=(entry_right!=_map.end()) ? entry_right->second.second : num;
            _map[range_left]=_map[range_right]=_map[num]=make_pair(range_left, range_right);
            maxSeq=max(maxSeq,range_right-range_left+1);
        }
        return maxSeq;
    }
};