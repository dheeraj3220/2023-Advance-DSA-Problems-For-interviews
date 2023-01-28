class Solution {
public:
    int bloomable(vector<int>&bloomDay,int m,int k, int cur ,int bouquet=0,int curFlow=0){
        for(auto bd:bloomDay){
            if(bd<=cur){
                curFlow++;
            }
            else{
                bouquet+=(curFlow/k);
                curFlow=0;
            }
        }
        bouquet+=(curFlow/k);
        return bouquet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=INT_MAX;
        int high=INT_MIN;
        for(auto bd:bloomDay){
            low=min(low,bd);
            high=max(high,bd);
        }
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(bloomable(bloomDay,m,k,mid)>=m){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};