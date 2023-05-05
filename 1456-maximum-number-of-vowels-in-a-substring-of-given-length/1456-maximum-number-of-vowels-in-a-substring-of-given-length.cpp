class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o'  || c=='u') return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int vowel=0;
        int maxVowel=0;
        while(j<s.size()){
            if((j-i)<k){
                if(isVowel(s[j])) vowel++;
                j++;
                
            }
            else{
                if(isVowel(s[i])) vowel--;
                if(isVowel(s[j])) vowel++;
                
                i++;
                j++;
            }
            maxVowel=max(maxVowel,vowel);
        }
        return maxVowel;
    }
};