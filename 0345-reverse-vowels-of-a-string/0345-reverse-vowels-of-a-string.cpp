class Solution {
public:
    bool isVowel(char ch){
        ch=tolower(ch);
        if(ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int i=0;
        int  j=s.size();
        while(i<j){
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i++],s[j--]);
            }
            else if(!isVowel(s[i])) i++;
            else {
                j--;
            }
        }
        return s;
    }
};