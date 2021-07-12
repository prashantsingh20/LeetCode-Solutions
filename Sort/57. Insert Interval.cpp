/* 57. Insert Interval
https://leetcode.com/problems/insert-interval/
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> result;
        int leftInterval = -1, rightInterval = -1;    
        
        // Calculate half-open intervals for newInterval's impact.
        // First interval that newInterval could impact = leftInterval.
        // FIrst interval that newInterval will not impact = rightInterval.
        for (int i = 0; i < intervals.size(); i++)
        {
            if ((newInterval[0] <= intervals[i][1]) &&
                (leftInterval == -1))
            {
                leftInterval = i;
            }
            if ((newInterval[1] < intervals[i][0]) &&
                (rightInterval == -1))
            {
                rightInterval = i;
            }
            if ((leftInterval != -1) &&
                (rightInterval != -1))
            {
                break;
            }
        }
        if (leftInterval == -1)
        {
            leftInterval = intervals.size();
        }
        if (rightInterval == -1)
        {
            rightInterval = intervals.size();
        }
        
        // Push intervals before the start of newInterval's impact.
        for (int i = 0; i < leftInterval; i++)
        {
            result.push_back(intervals[i]);
        }
        
        // Push the new merged interval.
        if (leftInterval == rightInterval)
        {
            result.push_back(newInterval);
        }
        else
        {
            result.push_back(
                { getLeftBoundary(intervals[leftInterval], newInterval[0]), 
                  getRightBoundary(intervals[rightInterval - 1], newInterval[1]) });    
        }
        
        // Push intervals after the end of newInterval's impact.
        for (int i = rightInterval; i < intervals.size(); i++)
        {
            result.push_back(intervals[i]);
        }
        
        return result;
    }
    
private:
    // Assumption: newLeftBoundary <= leftInterval[1]
    int getLeftBoundary(const vector<int>& leftInterval, int newLeftBoundary)
    {
        if (newLeftBoundary <= leftInterval[0])
        {
            return newLeftBoundary;
        }
        else
        {
            return leftInterval[0];
        }
    }
                
    // Assumption: newRightBoundary >= rightInterval[0]
    int getRightBoundary(const vector<int>& rightInterval, int newRightBoundary)
    {
        if (newRightBoundary >= rightInterval[1])
        {
            return newRightBoundary;
        }
        else
        {
            return rightInterval[1];
        }
    }
};