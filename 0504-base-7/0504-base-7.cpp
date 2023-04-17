class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        string s;
        string sign;
        if(num<0) sign+="-";
        num=abs(num);
        while(num>0){
            int rem=num%7;
            s+=to_string(rem);
            num/=7;
        }
        reverse(s.begin(),s.end());
        return sign+s;
    }
};