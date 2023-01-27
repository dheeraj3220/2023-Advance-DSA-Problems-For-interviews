class Solution {
public:
    int count(vector<vector<int>>&matrix,int mid){
        int i=matrix.size()-1;
        int j=0;
        int c=0;
        while(i>=0 && j<matrix.size()){
            if(mid<matrix[i][j]){
                i--;
            }
            else{
                c+=(i+1);
                j++;
            }
        }
        return c;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(count(matrix,mid)<k){
                low=mid+1;
            }
            else {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};