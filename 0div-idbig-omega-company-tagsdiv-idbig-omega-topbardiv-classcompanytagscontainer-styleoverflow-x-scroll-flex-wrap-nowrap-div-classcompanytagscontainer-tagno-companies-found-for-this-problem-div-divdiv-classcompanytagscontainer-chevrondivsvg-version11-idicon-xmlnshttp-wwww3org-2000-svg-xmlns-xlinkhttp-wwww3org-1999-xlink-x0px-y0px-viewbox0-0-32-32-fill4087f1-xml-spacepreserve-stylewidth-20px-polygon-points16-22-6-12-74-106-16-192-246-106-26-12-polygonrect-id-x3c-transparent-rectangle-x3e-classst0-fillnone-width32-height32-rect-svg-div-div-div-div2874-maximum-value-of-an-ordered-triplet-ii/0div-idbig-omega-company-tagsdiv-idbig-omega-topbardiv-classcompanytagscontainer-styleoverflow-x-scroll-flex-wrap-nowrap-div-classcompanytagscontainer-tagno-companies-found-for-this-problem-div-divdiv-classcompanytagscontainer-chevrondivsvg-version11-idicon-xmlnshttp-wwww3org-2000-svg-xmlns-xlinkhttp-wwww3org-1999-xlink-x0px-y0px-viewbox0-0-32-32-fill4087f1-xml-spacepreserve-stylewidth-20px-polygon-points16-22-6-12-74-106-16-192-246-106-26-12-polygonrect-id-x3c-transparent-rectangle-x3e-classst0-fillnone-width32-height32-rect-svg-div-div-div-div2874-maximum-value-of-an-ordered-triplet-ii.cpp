class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> mx(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            if(i==mx.size()-1) mx[i]=nums[i];
            else {
                int temp=0;
                temp=max(mx[i+1],nums[i]);
                mx[i]=temp;
            }
        }
        long long ans=0;
        long long a=nums[0];
        for(int i=1;i<nums.size()-1;i++){
            if(a-nums[i]<=0) a=nums[i];
            else{
                long long cur= (a-nums[i])*mx[i+1];
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};