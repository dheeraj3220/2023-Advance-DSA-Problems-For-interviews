class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=1e9+7;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        while(k--){
            int t=pq.top()+1;
            pq.pop();
            pq.push(t);
        }
        
        long long prod=1;
        while(pq.size()){
            prod=((prod*pq.top())%mod);
            pq.pop();
        }
        return prod%mod;
        
    }
};