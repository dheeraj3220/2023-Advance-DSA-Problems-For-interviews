class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mapp;
        for(auto ch: s) mapp[ch]++;
        for(auto ch: t){
            mapp[ch]--;
            if(mapp[ch]==0) mapp.erase(ch);
        }
        return mapp.size()==0;
    }
};