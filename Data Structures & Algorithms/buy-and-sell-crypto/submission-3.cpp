class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n=prices.size(),temp;
        if(n==0){return 0;}
        vector<int> profit(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int temp=prices[i]-prices[j];
                if(temp<profit[i-1]){
                    profit[i]=max(profit[i-1],profit[i]);
                }
                else profit[i]=max(temp,profit[i]);
            }
        }
        return profit[n-1];
    }
};
