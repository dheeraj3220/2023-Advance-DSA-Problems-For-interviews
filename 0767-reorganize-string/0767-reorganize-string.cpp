class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mapp(26,0);
        for(auto st : s) mapp[st-'a']++;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<26;i++){
            if(mapp[i]!=0) pq.push({mapp[i],i});
        }
          string res;
        
        while(!pq.empty()) {
            int index=pq.top().second;
            pq.pop();
            if(res.size()==0 || res.back()!=index+'a') res+=(index+'a');
            else return "";
            mapp[index]--;
            if(mapp[index]!=0 && !pq.empty()) {
                int index=pq.top().second;
                pq.pop();
                res+=(index+'a');
                mapp[index]--;
                if(mapp[index]!=0)pq.push({mapp[index],index});
            }
            if(mapp[index]!=0)pq.push({mapp[index],index});
        }
        
    
        return res;
    }
};