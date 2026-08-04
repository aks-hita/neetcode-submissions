class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string r=s;
        reverse(r.begin(),r.end());
        int maxLen = 0, endPos = 0;
        for(int i=1;i<= n;i++){
            for(int j=1;j<= n;j++){
                if(s[i-1]==r[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                     // Starting index in original string
                    int startOriginal = i - dp[i][j];
                    // Corresponding starting index from reversed string
                    int startReversed = n - j;

                    if (startOriginal == startReversed && dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        endPos = i;
                    }
                }
                else{
                   dp[i][j]=0;
                }
            }
        }
        return s.substr(endPos - maxLen, maxLen);;
    }
};
