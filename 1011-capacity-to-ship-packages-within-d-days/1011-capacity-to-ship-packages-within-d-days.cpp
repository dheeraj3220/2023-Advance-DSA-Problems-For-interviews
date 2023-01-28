class Solution {
public:
    int countDays(int mid,vector<int>&weights,int days){
        int cur=0;
        int reqDays=1;
        for(auto w:weights){
            cur+=w;
            if(cur<=mid) continue;
            else{
                cur=w;
                reqDays++;
            }
        }
        return reqDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =0;
        int high=0;
        for(auto w : weights){
            low=max(low,w);       //minimum capacity of day must be max of all weights
            high+=w;             //maximum capacity can be that we put all the wieghts in one day
        }
        
        while(low<high){
            int mid=(low+high)/2;
            if(countDays(mid,weights,days)<=days) high=mid;
            else low=mid+1;
        }
        return low;
        
    }
};     