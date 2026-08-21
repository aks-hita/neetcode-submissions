class Solution {
public:
    int time_req(vector<int>& piles, int amt){
        int result=0;
        for(int i=0;i<piles.size();i++){
            result+=ceil((double)piles[i]/amt);
        }
        return result;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h<piles.size()) return 0;
        int ans;
        int left=1; int right = *max_element(piles.begin(), piles.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            if(time_req(piles,mid)>h) left=mid+1;
            else{
                ans=mid;
                right=mid-1;
            }
        }
        return ans;
    }
};
