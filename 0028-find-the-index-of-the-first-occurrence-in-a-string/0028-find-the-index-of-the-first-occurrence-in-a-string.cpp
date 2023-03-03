class Solution {
public:
    int strStr(string haystack, string needle) {
        int size=needle.size();
        if(size>haystack.size()) return -1;
        for(int i=0;i<=haystack.size()-size;i++){
            if(haystack.substr(i,size)==needle) return i;
        }
        return -1;
    }
};