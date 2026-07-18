class Solution {
public:
bool alphaNum(char x){
        if(int(x)>=int('A') && int(x)<=int('Z')) return true;
        else if(int(x)>=int('a') && int(x)<=int('z')) return true;
        else if(int(x)>=int('0') && int(x)<=int('9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int l=0,r=s.length()-1;
        while(l<r){
            while(l<r && !alphaNum(s[l])){
                l++;
            }
            while(l<r && !alphaNum(s[r])){
                r--;
            }
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++; r--;
        }
        return true;
    }
    
};