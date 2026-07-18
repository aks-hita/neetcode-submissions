class Solution {
public:
    bool check(char c, stack<char> &st){
        if(c=='(' || c=='{' || c=='['){
            st.push(c);
            return true;
        }
        else if(st.empty()){
            return false;
        }
        else if(c==')' && st.top()=='('){
            st.pop();
            return true;
        }
        else if(c=='}' && st.top()=='{'){
            st.pop();
            return true;
        }
        else if(c==']' && st.top()=='['){
            st.pop();
            return true;
        }
        return false;
    }
    bool isValid(string s){
        if(s.size()<2){return false;}
        stack<char> st;
        bool flag=check(s[0],st);
        int i=1;
        while(flag && i<s.size()){
            flag=check(s[i],st);
            i++;
        }
        if(!st.empty()){return false;}
        return flag;
    }
};
