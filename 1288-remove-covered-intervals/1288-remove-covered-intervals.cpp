class Solution {
public:

    static bool sortbyCond(const vector<int>& a,
                const vector<int>& b)
{
    if (a[0] != b[0])
        return (a[0] < b[0]);
    else
       return (a[1] > b[1]);
}
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),sortbyCond);
        int start=intervals[0][0];
        int end=intervals[0][1];
        int count=1;
        for(int i=1;i<intervals.size();i++){
            if(end>=intervals[i][1]){
                continue;
            }
            start=intervals[i][0];
            end=intervals[i][1];
            count++;
        }
        return count;
    }
};