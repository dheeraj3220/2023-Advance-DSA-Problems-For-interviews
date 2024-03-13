class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0;
        priority_queue<int> pq;
        for(auto h:happiness) pq.push(h);
        int cur=0;
        while(k>0 && pq.size()){
            int tp=pq.top();
            if((tp-cur)>0){ tp-=cur;
            sum+=tp;
            }
            pq.pop();
            cur++;
            k--;
        }
        return sum;
    }
};