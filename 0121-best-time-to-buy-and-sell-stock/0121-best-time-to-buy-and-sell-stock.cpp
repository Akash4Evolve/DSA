class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int  profit= 0, minim= prices[0] , cost;
         for(int i = 0 ; i<prices.size(); i++){
            cost=prices[i]-minim;
            profit=max(profit,cost);
            minim= min(minim,prices[i]);
         }
         return profit;
        
    }
};