class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        while(pow(i,2)<x) i++;
        if(pow(i,2)==x) return i;
        return i-1;
    }
};