class Solution {
public:
    void build(vector<string>&result,string curr,int n,int open,int close){
        if(open==close && open==n){
            result.push_back(curr);
            return;
        }
        if(open<n && curr.size()<2*n-1){
            curr.push_back('(');
            build(result,curr,n,open+1,close);
            curr.pop_back();
        }
        if(close<n && close<open){
            curr.push_back(')');
            build(result,curr,n,open,close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string curr="(";
        build(result,curr,n,1,0);
        return result;
    }
};
