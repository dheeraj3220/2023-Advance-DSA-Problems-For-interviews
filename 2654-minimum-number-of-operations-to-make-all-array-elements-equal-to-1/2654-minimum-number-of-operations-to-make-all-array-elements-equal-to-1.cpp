class Solution {
public:
    int findGCD(vector<int> arr,int index){
        if(index==arr.size()-1) return arr[index];
        int a=arr[index];
        int b=findGCD(arr,index+1);
        return __gcd(a,b);
        
    }
    int minOperations(vector<int>& nums) {
        int mini=INT_MAX;
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) count1++;
            vector<int> subArr;
            for(int j=i;j<nums.size();j++){
                subArr.push_back(nums[j]);
                if(findGCD(subArr,0)==1) mini=min(j-i+1,mini);
            }
        }
        if(count1>0) return nums.size()-count1;
        return mini<INT_MAX?mini+nums.size()-2:-1;
    }
};