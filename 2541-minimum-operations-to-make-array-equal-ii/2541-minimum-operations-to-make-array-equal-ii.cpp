class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0) {
            if(nums1==nums2) return 0;
            else return -1;
        }
        int n=nums1.size();
        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            diff[i]=nums1[i]-nums2[i];
        }
        long long plus=0,minus=0;
        for(auto num: diff) {
            if(num<0) minus+=num;
            if(num>0) plus+=num;
        }
        if(plus==abs(minus)) {
            if(plus%k==0) {
                return plus/k;
            }
        }
        return -1;
        
    }
};