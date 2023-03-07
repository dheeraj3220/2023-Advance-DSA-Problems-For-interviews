#define pp pair<long long,int> 
class Solution {
public:
    
    long long countPossible(long long mid,vector<int>&time ){
        long long count=0;
        for(auto t:time)count+=(mid/t);
        return count;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low =0;
        long long high=1e14;
        
        while(low<high){
            long long mid=(low+high)/2;
            if(countPossible(mid,time)>=totalTrips)
                high=mid;
            else if (countPossible(mid,time)<totalTrips)
                low=mid+1;
        }
        return low;   
    }
};