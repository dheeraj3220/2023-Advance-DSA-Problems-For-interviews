class Solution {
public:
    string reversePrefix(string w, char ch) {
        string cur;
        bool found=false;
        for(int i=0;i<w.size();i++){
            if(!found && w[i]==ch) {
                cur+=w[i];
                reverse(cur.begin(),cur.end());
                found=true;
            }else {
                cur+=w[i];
            }
        }
        return cur;
    }
};