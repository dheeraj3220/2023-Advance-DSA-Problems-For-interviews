class Solution {
public:
    double minimumRequiredTime(int speed,vector<int>&dist,double hour){
        double totalTime=0.0;
        int i=0;
        for(i=0;i<dist.size()-1;i++){
            int d=dist[i];
            totalTime+=ceil((double)(d/(speed*1.0)));
        }
        totalTime+=(dist[i]/(speed*1.0));
        return totalTime;
    }
 
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=1e7;
        int res=1e9;
        while(low<=high){
            int mid=(low+high)/2;
            double ans=minimumRequiredTime(mid,dist,hour);
            if(hour<ans){
                low=mid+1;
            }
            else{
                high=mid-1;
                res=min(res,mid);
            }
        }
        return res>1e7?-1:res;
    }
};
