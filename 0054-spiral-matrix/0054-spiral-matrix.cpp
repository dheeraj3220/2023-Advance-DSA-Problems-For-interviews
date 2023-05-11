class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int top=0,left=0,down=mat.size()-1,right=mat[0].size()-1;
        
        while(top<=down && left<=right){
            for(int i=left;i<=right;i++){
                res.push_back(mat[top][i]);
            }
            top++;
            for(int i=top;i<=down;i++){
                res.push_back(mat[i][right]);
            }
            right--;
            if(top<=down){
            for(int i=right;i>=left;i--){
                res.push_back(mat[down][i]);
            }
            down--;
            }
            if(left<=right){
            for(int i=down;i>=top;i--){
                res.push_back(mat[i][left]);
            }
            left++;
            }
        }
        return res;
    }
};