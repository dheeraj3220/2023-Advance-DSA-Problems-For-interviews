class Solution {
public:
    void findComb(int k,int n,vector<vector<int>>&res,vector<int>temp,int index){
        if(k==0){
            if(n==0) {
                res.push_back(temp);
            }
            return ;
        }
        for(int i=index;i<=9;i++){
            if(n-i<0) break;
            temp.push_back(i);
            findComb(k-1,n-i,res,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        findComb(k,n,res,temp,1);
        return res;
    }
};