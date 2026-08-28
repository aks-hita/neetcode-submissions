class Solution {
public:
    int dfs(int ind, vector<int>&cost,vector<int>&climb,vector<bool>&visited){
        if(ind>=cost.size())
            return 0;
        if(!visited[ind]){
            visited[ind]=true;
            climb[ind]=min(dfs(ind+1,cost,climb,visited),dfs(ind+2,cost,climb,visited));
        }
        return(cost[ind]+climb[ind]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> climb(cost.size());
        vector<bool>visited(cost.size(),false);
        return min(dfs(0,cost,climb,visited),dfs(1,cost,climb,visited));  
    }
};
