class Solution {
public:
    int dfs(vector<int>& prices,int ind, bool canBuy, vector<vector<int>>& dp){
        if(ind>=prices.size()){return 0;}
        if(dp[ind][canBuy]!= -1) return dp[ind][canBuy];
        if(canBuy){
            int buy=dfs(prices,ind+1,false,dp)-prices[ind];
            int skip=dfs(prices,ind+1,true,dp);
            dp[ind][canBuy]=max(buy,skip);
        }
        else{
            int sell=dfs(prices,ind+2,true,dp)+prices[ind];
            int skip=dfs(prices,ind+1,false,dp);
            dp[ind][canBuy]=max(sell,skip);
        }
        return dp[ind][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(prices,0,true,dp);
    }
};
