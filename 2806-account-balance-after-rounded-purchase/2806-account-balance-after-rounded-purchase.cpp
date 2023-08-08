class Solution {
public:
    int accountBalanceAfterPurchase(int x) {
        int rem;
    int ans=x/10;
    int finalans;
    rem=x%10;
    if(rem<5){
       ans=ans*10; 
    }else{
        ans=(ans+1)*10;
    }
    
    finalans=100-ans;
    return finalans;
    }
};