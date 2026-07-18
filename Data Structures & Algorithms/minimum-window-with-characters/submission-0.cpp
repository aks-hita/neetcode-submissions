class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_let;
        for(char c:t){
            t_let[c]++;
        }
        unordered_map<char,int> s_let;
        int curr=0,length=0,bestlen=s.size()+1,beststart=0;
        int formed=0,required=t_let.size();
        for(int last=0;last<s.size();last++){
            s_let[s[last]]++;
            auto it=t_let.find(s[last]);
            if(it!=t_let.end()){
                if(s_let[s[last]]==it->second) formed++;
            }
            while(formed==required){
                auto it=t_let.find(s[curr]);
                if(it==t_let.end() || s_let[s[curr]]>it->second){
                    
                    s_let[s[curr]]--;
                    curr++;
                }
                else{
                    break;
                }
            }
            if(formed==required){
                length=last-curr+1;
                if(length<bestlen){
                    beststart=curr;
                    bestlen=length;
                }
            }
        }
        if(bestlen>s.size()){return "";}
        return s.substr(beststart,bestlen);
    }
};