class Solution {
public:
    bool valid_one_dig(string &s,int ind){
        if(s[ind]-'0'==0) return false;
        return true;
    }
    bool valid_two_dig(string &s, int ind){
        if(s[ind]-'0'==0 || s[ind]-'0'>2) return false;
        if(ind==s.size()-1) return false;
        int num= ((s[ind]-'0')*10)+(s[ind+1]-'0');
        if(num>9 && num<27) return true;
        return false;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>f(n+1);
        f[n]=1;
        if(n==1){
            if(s[0]-'0'==0) return 0;
            return 1;
        }
        for(int i=n-1;i>=0;i--){
            f[i]=(valid_one_dig(s,i)?f[i+1]:0)+(valid_two_dig(s,i)?f[i+2]:0);
        }
        return f[0];
    }
};
