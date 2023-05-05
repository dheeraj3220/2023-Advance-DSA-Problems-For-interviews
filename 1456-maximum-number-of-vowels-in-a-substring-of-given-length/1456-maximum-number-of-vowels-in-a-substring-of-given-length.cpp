class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int vowel=0;
        int maxVowel=0;
        while(j<s.size()){
            if((j-i)<k){
                char c=s[j];
                if(c=='a' || c=='e' || c=='i' || c=='o'  || c=='u') vowel++;
                j++;
                
            }
            else{
                char c=s[i];
                if(c=='a' || c=='e' || c=='i' || c=='o'  || c=='u') vowel--;
                c=s[j];
                if(c=='a' || c=='e' || c=='i' || c=='o'  || c=='u') vowel++;
                i++;
                j++;
            }
            maxVowel=max(maxVowel,vowel);
        }
        return maxVowel;
    }
};