class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> curRow(i+1,0);
            curRow[0]=1;
            curRow[i]=1;
            for(int j=1;j<i;j++){
                if(res.size()>1) curRow[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(curRow);
        }
        return res;
    }
};