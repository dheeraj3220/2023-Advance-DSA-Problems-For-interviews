class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=0;i<n;i++){
            string invertedS=invert(s);
            reverse(invertedS.begin(),invertedS.end());
            s+=("1" + invertedS);
            if(s.size()>=k) return s[k-1];
        }
        return s[k-1];
        
    }
};
