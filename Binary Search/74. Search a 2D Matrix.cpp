//74. Search a 2D Matrix
//https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
int row( std::vector<std::vector<int>>v,int start,int end,int k  )
{
        if(start<=end)
        {
                int mid = start +(end-start)/2;
                if(v[mid][0]<=k && v[mid][v[mid].size()-1]>=k)
                {
                        return mid;
                }
                if(v[mid][0]>k)
                {
                        return(row(v,start,mid-1,k));
                }
                else
                {
                        return(row(v,mid+1,end,k));
                }
        }
        else
        {
                return -1;
        }
}
int column(std::vector<std::vector<int>> v,int row,int start,int end,int k)
{
        if(start<=end)
        {
                int mid = start+(end-start)/2;
                if(v[row][mid]==k)
                {
                        return mid;
                }
                if(v[row][mid]>k)
                {
                        return(column(v,row,start,mid-1,k));
                }
                else
                {
                        return(column(v,row,mid+1,end,k));
                }
        }
        else
        {
                return -1;
        }
}


bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int rowIndex = row(matrix,0,n-1,target);
        if(rowIndex!=-1)
        {
                int m = matrix[rowIndex].size();
                int columnIndex=column(matrix,rowIndex,0,m-1,target);
                if(columnIndex!=-1)
                {
                        return true;
                }
        }
        return false;

}
};