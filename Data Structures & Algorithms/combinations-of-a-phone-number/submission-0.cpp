class Solution {
public:
    void comb(vector<string> &result, string digits,int num,string curr){
        vector<vector<char>> but={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
        {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        if(curr.size()==digits.size()){
            result.push_back(curr);
            return;
        }
        int n=digits[num]-'2';
        for(char c: but[n]){
            curr.push_back(c);
            comb(result,digits,num+1,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits==""){return {};}
        string curr="";
        comb(result,digits,0,curr);
        return result;
    }
};
