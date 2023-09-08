class Solution {
public:
    int lengthOfLastWord(string s) {
        string res;
        int i=s.size()-1;
        while(i>=0 && s[i]==' ') i--;
        while(i>=0 && s[i]!=' ') res+=s[i--];
        return res.size();
    }
};