class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1=0,res=0;
        for(auto it : s){
            if(it=='1') count1++;
            else{
                res=min(count1,res+1);
            }
        }
        return res;
    }
};