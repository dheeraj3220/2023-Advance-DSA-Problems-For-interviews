class Solution {
public:
    string removeKdigits(string nums, int k) {
        string res;
        if(nums.size()==1) return "0";
        for(int i=0;i<nums.size();i++){
            if(k==0 || (res.size()==0 && nums[i]!='0') || res.back()<=nums[i]){
                if(res.size()==0 && nums[i]=='0') continue;
                res.push_back(nums[i]);
            }
            else {
                if(res.size()==0 && nums[i]=='0') continue;
                res.pop_back();
                k--;
                i--;
            }
        }
        while(k>0){
            if(res.size()) res.pop_back();
            k--;
        }
        return res==""?"0":res;
    }
};