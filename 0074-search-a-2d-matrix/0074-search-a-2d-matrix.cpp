class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,col=matrix[0].size(), high=(matrix.size()*col)-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            int x=mid/col;
            int y=mid%col;
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y]<target) low=mid+1;
            else high=mid-1;  
        }
        return false;
        
    }
};