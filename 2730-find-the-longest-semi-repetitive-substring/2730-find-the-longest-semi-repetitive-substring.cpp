class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i=0,j=0;
        int maxLen=0;
        int cnt=0;
        while(j<s.size()){
            if(j>0 && s[j]==s[j-1]){
                while(cnt>0 && i<j){
                    if(s[i]==s[i+1]) cnt--;
                    i++;
                }
                cnt++;
            } 
            j++;
            maxLen=max(maxLen,j-i);
        }
        return maxLen;
    }
};