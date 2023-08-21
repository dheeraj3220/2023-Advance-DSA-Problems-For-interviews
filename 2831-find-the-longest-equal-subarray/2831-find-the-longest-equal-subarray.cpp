class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        map<int,int> mapp;
        int i=0,j=0;
        int maxi=0;
        while(j<nums.size()){
            // if(j-i+1-maxi<=k){
                mapp[nums[j]]++;
                maxi=max(mapp[nums[j]],maxi);
                // j++;
            // }
            while(j-i+1-maxi>k && i<j){
                mapp[nums[i]]--;
                i++;
            }
            j++;
        }
        
        return maxi;
    }
};