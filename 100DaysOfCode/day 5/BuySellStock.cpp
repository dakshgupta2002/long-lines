
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int buy=prices[0], profit=0; 
        
        for(int i=1; i<n; i++){
            if (prices[i] < buy){
                buy = prices[i];
            }else{
                profit = max(profit, prices[i]-buy);
            }
        }
        
        return profit; 
    }
};