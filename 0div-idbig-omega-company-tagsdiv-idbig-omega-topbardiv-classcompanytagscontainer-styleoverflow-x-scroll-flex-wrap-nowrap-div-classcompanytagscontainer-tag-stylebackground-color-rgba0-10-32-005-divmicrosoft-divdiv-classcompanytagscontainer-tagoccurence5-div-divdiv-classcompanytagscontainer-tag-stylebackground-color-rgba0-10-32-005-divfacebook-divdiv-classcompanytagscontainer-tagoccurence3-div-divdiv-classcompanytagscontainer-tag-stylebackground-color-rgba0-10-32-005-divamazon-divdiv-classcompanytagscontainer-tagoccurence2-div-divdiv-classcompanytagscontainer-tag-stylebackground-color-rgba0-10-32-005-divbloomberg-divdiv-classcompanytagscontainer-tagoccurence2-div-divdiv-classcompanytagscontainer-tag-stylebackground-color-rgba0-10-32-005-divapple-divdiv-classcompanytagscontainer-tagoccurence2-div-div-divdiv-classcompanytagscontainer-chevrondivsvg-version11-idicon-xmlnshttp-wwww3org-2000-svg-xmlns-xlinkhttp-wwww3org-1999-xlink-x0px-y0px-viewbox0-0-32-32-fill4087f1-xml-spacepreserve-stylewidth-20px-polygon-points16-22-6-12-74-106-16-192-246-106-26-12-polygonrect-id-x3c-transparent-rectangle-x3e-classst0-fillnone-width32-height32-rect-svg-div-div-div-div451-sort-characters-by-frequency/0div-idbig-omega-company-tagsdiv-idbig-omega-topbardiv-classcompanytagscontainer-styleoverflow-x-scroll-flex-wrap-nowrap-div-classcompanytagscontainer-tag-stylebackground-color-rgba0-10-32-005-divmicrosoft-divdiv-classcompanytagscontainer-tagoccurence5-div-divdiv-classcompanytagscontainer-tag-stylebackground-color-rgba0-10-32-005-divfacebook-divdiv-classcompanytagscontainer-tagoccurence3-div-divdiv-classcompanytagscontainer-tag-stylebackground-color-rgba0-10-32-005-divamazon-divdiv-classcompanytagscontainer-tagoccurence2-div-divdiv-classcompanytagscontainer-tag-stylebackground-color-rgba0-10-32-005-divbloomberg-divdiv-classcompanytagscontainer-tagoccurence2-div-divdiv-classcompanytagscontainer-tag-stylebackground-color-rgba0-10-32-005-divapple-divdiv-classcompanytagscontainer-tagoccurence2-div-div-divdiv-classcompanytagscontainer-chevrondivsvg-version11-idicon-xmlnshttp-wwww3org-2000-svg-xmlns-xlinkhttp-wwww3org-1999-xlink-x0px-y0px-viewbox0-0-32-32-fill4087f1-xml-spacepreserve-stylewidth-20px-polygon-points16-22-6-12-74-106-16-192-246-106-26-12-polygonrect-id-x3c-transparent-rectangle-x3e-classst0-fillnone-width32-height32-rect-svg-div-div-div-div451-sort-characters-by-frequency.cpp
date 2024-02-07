class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mapp;
        for(auto si :s) {
            mapp[si]++;
        }
        priority_queue<pair<int,char>> pq;
        
        for(auto i=mapp.begin();i!=mapp.end();i++){
            if(i->second) pq.push({i->second,i->first});
        }
        string res;
        while(pq.size()){
            char currentCharacter =pq.top().second;
            int occurence=pq.top().first;
            for(int i=0;i<occurence;i++) res+=currentCharacter;
            pq.pop();
        }
        return res;
    }
};