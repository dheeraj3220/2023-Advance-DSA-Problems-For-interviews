class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<groupSizes.size();i++){
            pq.push({groupSizes[i],i});
        }
        vector<int> temp;
        while(!pq.empty()){
            temp.push_back(pq.top().second);
            
            if(temp.size() && pq.top().first==temp.size()){
                res.push_back(temp);
                temp.clear();
            }
            pq.pop();
        }
        return res;
        
    }
};