class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> que;
        for(int i=0;i<tickets.size();i++){
            que.push({i,tickets[i]});
        }
        
        int time=0;
        while(que.size()){
            time++;
            pair<int,int> frt=que.front();
            if(frt.first==k && frt.second==1) return time;
            que.pop();
            if(frt.second-1>0)que.push({frt.first,frt.second-1});
        }
        return 0;
    }
};