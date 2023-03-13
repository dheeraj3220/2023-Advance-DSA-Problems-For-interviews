class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
          sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    int totalTime=0;
    unordered_map<int,int> mapp;
        for(auto task:tasks){
            int curTaskTime=task[2];
            int endTime=task[1];
            int startTime=task[0];
            while(curTaskTime && startTime<=endTime){
                if(mapp.count(startTime)) curTaskTime--;
                else if(startTime+curTaskTime>endTime){
                    totalTime++;
                    mapp[startTime]++;
                    curTaskTime--;
                }
                startTime++;
            }
            
            // while(curTaskTime--){
            //     mapp[endTime]++;
            //     endTime--;
            // }
        }
        return totalTime;
        
        
        
    }
};