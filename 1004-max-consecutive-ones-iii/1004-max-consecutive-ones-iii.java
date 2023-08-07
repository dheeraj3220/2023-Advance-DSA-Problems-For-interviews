class Solution {
    public int longestOnes(int[] nums, int k) {
        int len = nums.length;
        int start = 0;
        int noOfFlipsRemaining = k;
        int i=0,j=0;
        int overallMax = 0;
        while(i<=j && j<len){
            if(nums[j]==1){
            overallMax = Math.max(j-i+1,overallMax);      
                j++;
            } else {
                if(noOfFlipsRemaining>0){
                    nums[j] = 2;
                    noOfFlipsRemaining--;
                    overallMax = Math.max(j-i+1,overallMax);
                    j++;
                }else {
                    while(nums[i]==1){
                        i++;
                    }
                    if(i<len && nums[i]==2){
                        nums[i]=0;
                        i++;
                        noOfFlipsRemaining++;
                    }
                    if(i<len && i==j && nums[i]==0){
                        i++;
                        j++;
                    }
                }
            }
        }
        return overallMax;
    }
}