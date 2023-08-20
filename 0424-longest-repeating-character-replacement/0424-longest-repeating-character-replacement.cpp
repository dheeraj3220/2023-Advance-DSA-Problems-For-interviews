class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        map<char,int> mapp;
        int localMaxi=0;
        int maxi=0;
        while(j<s.size()){
            mapp[s[j]]++;
            localMaxi=max(mapp[s[j]],localMaxi);
                while(j-i+1-localMaxi>k){
                    mapp[s[i]]--;
                    localMaxi=max(mapp[s[i]],localMaxi);
                    i++;
                }
            maxi=max(j-i+1,maxi);
            j++;
            
        }
        return maxi;
    }
};