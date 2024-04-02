class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapp1;
        unordered_map<char,char> mapp2;
        for(int i=0;i<s.size();i++){
            if(mapp1.count(s[i]) && mapp1[s[i]]!=t[i] && mapp2[t[i]]!=s[i]) return false;
            else if(mapp2.count(t[i]) && mapp2[t[i]]!=s[i] && mapp1[s[i]]!=t[i]) return false;
            else{
                mapp1[s[i]]=t[i];
                mapp2[t[i]]=s[i];
            }
        }
        return true;
    }
};