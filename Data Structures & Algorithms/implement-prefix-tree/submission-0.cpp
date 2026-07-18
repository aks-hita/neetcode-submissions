class PrefixTree {
public:
    PrefixTree* children[26];
    bool isEndofWord=false;
    PrefixTree() {
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
    ~PrefixTree(){
        for(int i=0;i<26;i++){
            delete children[i];
        }
    }
    void insert(string word) {
        PrefixTree* curr=this;
        for(char s: word){
            if(curr->children[s-'a']==nullptr){
                curr->children[s-'a']=new PrefixTree;
            }
            curr=curr->children[s-'a'];
        }
        curr->isEndofWord=true;
    }
    
    bool search(string word) {
        PrefixTree* curr=this;
        for(char s: word){
            if(curr->children[s-'a']==nullptr){
                return false;
            }
            curr=curr->children[s-'a'];
        }
        return curr->isEndofWord;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* curr=this;
        for(char s: prefix){
            if(curr->children[s-'a']==nullptr){
                return false;
            }
            curr=curr->children[s-'a'];
        }
        return true;
    }
};
