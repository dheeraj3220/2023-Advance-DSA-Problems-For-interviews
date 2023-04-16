class Solution {
public:
    int addMinimum(string word) {
        int count=0;
        if(word[0]=='b') count++;
        if(word[0]=='c') count+=2;
        
        for(int i=0;i<word.size();i++){
            if(word[i]=='a'){
                if(word[i+1]=='a' || word[i+1]=='\0') count+=2;
                else if(word[i+1]=='c') count+=1;
            }
            else if(word[i]=='b'){
                if(word[i+1]=='a' || word[i+1]=='\0') count+=1;
                else if(word[i+1]=='b') count+=2;
            }
            else if(word[i]=='c'){
                if(word[i+1]=='a' || word[i+1]=='\0') count+=0;
                else if(word[i+1]=='b') count+=1;
                else{
                    count+=2;
                }
            }
        }
        return count;
        
    }
};