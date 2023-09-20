class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt1(26,0),cnt2(26,0);
        for(auto it :s) cnt1[it-'a']++;
        for(auto it :t) cnt2[it-'a']++;
        for(int i=0;i<26;i++){
            if(cnt2[i]-cnt1[i]==1) return 'a'+i;
        }
        return 'a';
        
    }
};