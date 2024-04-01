class Solution {
public:
    int lengthOfLastWord(string s) {
        bool wordFound=false;
        int count=0;
        for(int i=s.size()-1;i>=0;i--){
            if(wordFound && s[i]==' ') return count;
            else if(s[i]!=' '){
                count++;
                wordFound=true;
            }
        }
        
        return count;
    }
};