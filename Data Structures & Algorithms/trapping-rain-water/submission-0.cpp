class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        vector<int>prefix(height.size());
        vector<int>suffix(height.size());
        int water=0;
        int h_max=height[0];
        prefix[0]=0;
        for(int i=1;i<height.size();i++){
            prefix[i]=h_max;
            h_max=max(h_max,height[i]);
        }
        h_max=height[height.size()-1];
        suffix[height.size()-1]=0;
        for(int i=height.size()-2;i>=0;i--){
            suffix[i]=h_max;
            h_max=max(h_max,height[i]);
        }
        for(int i=0;i<height.size();i++){
            water+=(max(0,min(prefix[i],suffix[i])-height[i]));
        }
        return water;
    }
};
