class Solution {
public:
    int partitionString(string s) {
        int count=0;
        map<char,int> mapp;
        for(int i=0;i<s.size();i++){
            if(mapp.count(s[i])==0) mapp[s[i]]++;
            else{
                count++;
                mapp.clear();
                mapp[s[i]]++;
            }
        }
        return count+1;
    }
};