class Solution {
public:
    bool isPossible(long long mid,vector<int>&piles,int h){
        int countHours=0;
        for(auto p: piles){
            countHours+=(p/mid);
            if(p%mid!=0) countHours+=1;
            if(countHours>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long  low=0;
        long long  high=1e9;
        for(auto p :piles){
            low=low>p?p:low;
            high=high<p?p:high;
        }
        while(low<high){
            long long mid=(low+high)/2;
            if(mid==0){
                low=1;
                continue;
            }
            if(isPossible(mid,piles,h)){
                high=mid;
            }
            else {
                low=mid+1;
            }
        }
        return low;
        
    }
};