class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> m;
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    string get(string key, int timestamp) {
        int ans=-1;
        int left=0; int right=m[key].size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(m[key][mid].first<=timestamp){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        if(ans== -1) return "";
        return m[key][ans].second;
    }
};
