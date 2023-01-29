class Solution {
public:
    int monkeyMove(int n) {
        int mod=1e9+7;
        //2^n-2
        long res=1,base=2;
        while(n>0){
            if (n % 2)
                res = (res * base) % mod;
            base = (base * base) % mod;
            n >>= 1;
        }
        return (res-2+mod)%mod;
        
        
    }
};