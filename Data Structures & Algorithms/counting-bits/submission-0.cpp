class Solution {
public:
    int count_one(int n){
        int count=0;
        while(n>0){
            if(n%2==1) count++;
            n=n/2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>result;
        for(int i=0;i<=n;i++){
            result.push_back(count_one(i));
        }
        return result;
    }
};
