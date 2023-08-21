class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i=0,j=0;
        int maxLen=0,maxFreq=0;
        unordered_map<char,int> mapp;
        while(j<s.size()){
            mapp[s[j]]++;
            maxFreq=max(maxFreq,mapp[s[j]]);
            while(j-i+1-maxFreq>k){
                mapp[s[i]]--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};