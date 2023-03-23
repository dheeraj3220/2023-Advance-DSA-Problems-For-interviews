class Solution {
public:
    int compress(vector<char>& chars) {
        int start=0,end=0,count=0,curPointer=0;
        string countToString;
        while(end<chars.size()){
            if(chars[start]==chars[end]){
                count++;
                end++;
            }
            else{
                if(count==1){
                    chars[curPointer]=chars[start];
                    curPointer++;
                    start=end;
                    count=0;
                    continue;
                }
                countToString=to_string(count);
                chars[curPointer]=chars[start] ;
                curPointer++;
                for(auto cts:countToString){
                    chars[curPointer]=cts;
                    curPointer++;
                }
                start=end;
                count=0;
                countToString="";
            }
        }
        if(count!=1) countToString=to_string(count);
        chars[curPointer]=chars[start] ;
        curPointer++;
        for(auto cts:countToString){
                    chars[curPointer]=cts;
                    curPointer++;
        }
        return curPointer;
        
    }
};