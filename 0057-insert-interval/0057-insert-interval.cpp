class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        vector<int> temp(2);
        int newStart=newInterval[0];
        int newEnd=newInterval[1];
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newStart) res.push_back(intervals[i++]);
        if(i==intervals.size()){
            res.push_back(newInterval);
            return res;
        }
        if(intervals[i][0]>newEnd) res.push_back({newStart,newEnd});
        else{
            int start=min(newStart,intervals[i][0]);
            int end=max(newEnd,intervals[i][1]);
            i++;
            while(i<intervals.size() && intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
                i++;
            }
            res.push_back({start,end});
        }
        while(i<intervals.size()) res.push_back(intervals[i++]);
        return res;
    }
};