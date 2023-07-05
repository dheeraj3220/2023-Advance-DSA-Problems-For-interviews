class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen=0;
        int flag=0;
        int len=0;
        int afterZeroLength=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1 && flag==0) len++;
            else if(nums[i]==1 && flag==1) afterZeroLength++;
            else if(nums[i]==0 && flag==0 && (maxLen!=0 || len!=0) ){
                flag++;
            }
            else if(nums[i]==0 && flag==1){
                flag=0;
                cout<<len<<" --- "<<afterZeroLength<<endl;
                maxLen=max((len+afterZeroLength),maxLen);
                len=afterZeroLength;
                afterZeroLength=0;
                i--;
            }
        }
        maxLen=max((len+afterZeroLength),maxLen);
        if(maxLen==nums.size()) return maxLen-1;
        return maxLen;
    }
};