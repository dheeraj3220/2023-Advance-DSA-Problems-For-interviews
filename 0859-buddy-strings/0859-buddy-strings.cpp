class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if( s.size()!=goal.size()) return false;
        int cntS[26]={0};
        int cntG[26]={0};
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]) cnt++;
            if(cnt>2) return false; 
            cntS[s[i]-'a']++;
            cntG[goal[i]-'a']++;
        }
        int can=0;
        for(int i=0;i<26;i++){
            if(cntS[i]!=cntG[i]) return false;
            if(cntS[i]>=2) can++; 
        }
        if(can<1 && cnt!=2) return false;
        return true;
    }
};