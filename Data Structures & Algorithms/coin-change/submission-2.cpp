class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> a(n+1,vector<int>(amount+1));
        for(int k=0;k<amount+1;k++){
            a[0][k]=amount+1;
        }
        for(int k=0;k<n+1;k++){
            a[k][0]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                a[i][j]=a[i-1][j];
                if(j-coins[i-1]>=0 && a[i][j-coins[i-1]]<=amount){
                    a[i][j]=min(a[i-1][j],1+a[i][j-coins[i-1]]);
                }
            }
        }
        if(a[n][amount]>amount) return -1;
        return a[n][amount];
    }
};
