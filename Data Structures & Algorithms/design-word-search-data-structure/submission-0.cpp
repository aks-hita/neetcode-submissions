class WordDictionary {
public:
    WordDictionary* alphabet[26];
    bool isEndofWord=false;
    WordDictionary() {
        for(int i=0;i<26;i++){
            alphabet[i]=nullptr;
        }
    }
    ~WordDictionary(){
        for(int i=0;i<26;i++){
            delete alphabet[i];
        }
    }
    void addWord(string word) {
        WordDictionary* curr=this;
        for(char s:word){
            if(curr->alphabet[s-'a']==nullptr){
                WordDictionary* temp=new WordDictionary;
                curr->alphabet[s-'a']=temp;
            }
            curr=curr->alphabet[s-'a'];
        }
        curr->isEndofWord=true;
    }
    bool check(WordDictionary* curr, string word,int ind){
        if(curr==nullptr) return false;
        if(ind==word.size()) return curr->isEndofWord;
        if(word[ind]=='.'){
            for(int i=0;i<26;i++){
                if(curr->alphabet[i]!=nullptr)
                    if(check(curr->alphabet[i],word,ind+1)) return true;
            }
            return false;
        }
        if(curr->alphabet[word[ind]-'a']==nullptr){return false;}
        return check(curr->alphabet[word[ind]-'a'],word,ind+1);
    }
    bool search(string word) {
        WordDictionary* curr=this;
        return check(curr,word,0);
    }
};
