class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack <int> stk;
        vector<int> res(prices.size(),0);
        for(int i=prices.size()-1;i>=0;i--){
            if(stk.size()==0){
                res[i]=prices[i];
                stk.push(prices[i]);
                continue;
            }
            while(stk.size() && stk.top()>prices[i]) stk.pop();
            if(stk.size()) res[i]=prices[i]-stk.top();
            else res[i]=prices[i];
            stk.push(prices[i]);
        }
        return res;
    }
};