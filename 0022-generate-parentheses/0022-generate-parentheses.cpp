class Solution {
public:
    void generate(vector<string>&res,string s,int m,int n){
        if(n==0 && m==0){
            res.push_back(s);
            return;
        }
        if(m>0) generate(res,s+")",m-1,n);
        if(n>0) generate(res,s+"(",m+1,n-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        generate(res,s,0,n);
        return res;
    }
};