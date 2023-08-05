class Solution {
public:
    int accountBalanceAfterPurchase(int pa) {
        return pa%10<5?100-(pa/10)*10:100-((pa/10)+1)*10;
    }
};