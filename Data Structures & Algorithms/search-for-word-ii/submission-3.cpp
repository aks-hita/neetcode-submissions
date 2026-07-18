class Trie{
public:
    Trie* alphabet[26];
    bool isEndofWord=false;
    string word;
    Trie(){
        for(int i=0;i<26;i++){
            alphabet[i]=nullptr;
        }
    }
    ~Trie(){
        for(int i=0;i<26;i++){
            delete alphabet[i];
        }
    }
    void add(string word){
        Trie* curr=this;
        for(char s:word){
            if(curr->alphabet[s-'a']==nullptr){
                Trie* temp=new Trie;
                curr->alphabet[s-'a']=temp;
            }
            curr=curr->alphabet[s-'a'];
        }
        curr->isEndofWord=true;
        curr->word=word;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>result;
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        Trie tree;
        for(int i=0;i<words.size();i++){
            tree.add(words[i]);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                search(visited,result,&tree,board,i,j);
            }
        }
        return result;
    }
    void search(vector<vector<bool>>&visited,vector<string>&result,Trie* root, vector<vector<char>>&board,int r, int c){
        if(r==board.size()||c==board[0].size()||r<0||c<0) return;
        if(visited[r][c]) return;
        if(root->alphabet[board[r][c]-'a']==nullptr) return;
        visited[r][c]=true;
        root=root->alphabet[board[r][c]-'a'];
        if(root->isEndofWord){
            result.push_back(root->word);
            root->isEndofWord=false;
        }
        search(visited,result,root,board,r-1,c);
        search(visited,result,root,board,r,c-1);
        search(visited,result,root,board,r+1,c);
        search(visited,result,root,board,r,c+1);
        visited[r][c]=false;
        return; 
    }
};