class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row=0;
        int maxCount=0;
        for(int i=0;i<mat.size();i++){
            int curOne=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) curOne++;
            }
            if(curOne>maxCount){
                row=i;
                maxCount=curOne;
            }
        }
        return {row,maxCount};
    }
};