class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mapp;
        for(auto st : t) mapp[st]++;
        int i=0,j=0;
        int count=mapp.size();
        int start=0, end =INT_MAX;
        string res="";
        int minLen=INT_MAX;
        while(j<s.size()){
            if(mapp.count(s[j])==0) j++;
            else if(count!=0){
                mapp[s[j]]--;
                if(mapp[s[j]]==0) count--;
                j++;
            }
                while(count==0){
                    if(minLen>j-i){
                     start=i;
                        end=j;
                     minLen=j-i;
                    }
                    if(mapp.count(s[i])==1){
                        mapp[s[i]]++;
                        if(mapp[s[i]]>0) count++;
                    }
                    i++;
                }
        }
        if(end-start!=INT_MAX)
        return s.substr(start,end-start);
        return "";
        
    }
};