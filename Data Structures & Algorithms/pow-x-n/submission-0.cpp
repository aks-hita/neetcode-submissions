class Solution {
public:
    double myPow(double& x, int n) {
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n==-1) return 1/x;
        if(n%2==0){
            double res=myPow(x,n/2);
            return res*res;
        }
        double res;
        if(n<0){res=myPow(x,(n+1)/2); return (1/x)*res*res;}
        else
            res=myPow(x,(n-1)/2);
        return x*res*res;
    }
};
