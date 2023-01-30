struct compare{
    bool operator()(pair<int,string>a,pair<int,string>b){
        if(a.first==b.first)
            return a.second>b.second;
        else 
            return a.first<b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mapp;
        for(auto word: words) mapp[word]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
        for(auto i=mapp.begin();i!=mapp.end();i++){
            pq.push({i->second,i->first});
        }
        vector<string> res;
        while(!pq.empty() && k){
            string s=pq.top().second;
            pq.pop();
            res.push_back(s);
            k--;
        }
        return res;
        
    }
};