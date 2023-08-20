class Solution {
public:
    string helper(string s,int & index){
        if(index==s.size()) return "";
        string res;
        string numstr="";
        while(index<s.size()){
            if(s[index]>='0' && s[index]<='9'){
                numstr+=s[index];
            }else if(s[index]>='a' && s[index]<='z') res+=s[index];
            else if(s[index]==']') return res;
            else if(s[index]=='[') {
                index+=1;
                string ans=helper(s,index);
                int num=stoi(numstr);
                while(--num) res+=ans;
                res+=ans;
                numstr="";
            }
            index++;
            
        }
        return res;
        
    }
    string decodeString(string s) {
        int index=0;
        return helper(s,index);
    }
};