class Solution {
public:
    int characterReplacement(string s, int k) {
        int curr=0,length,result=0;
        vector<int> letter(26,0);
        for(int last=0;last<s.length();last++){
            letter[s[last]-'A']++;
            auto it= max_element(letter.begin(),letter.end());
            int best=*it;
            while((last-curr-best+1)>k && curr<s.size()){
                letter[s[curr]-'A']--;
                curr++;
            }
            length=last-curr+1;
            result=max(result,length);
        }
        return result;
    }
};