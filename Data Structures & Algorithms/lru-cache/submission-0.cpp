class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        prev=next=nullptr;
    }
    Node(){
        key=-1;
        val=-1;
        prev=next=nullptr;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
    int capacity;
    void remove(int key){
        Node* curr=cache[key];
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        cache.erase(key);
        delete curr;
    }
    void insert(int key, int value){
        Node* curr= new Node(key,value);
        curr->prev=right->prev;
        curr->next=right;
        right->prev->next=curr;
        right->prev=curr;
        cache[key]=curr;
    }
    LRUCache(int capacity) {
        left=new Node;
        right=new Node;
        left->next=right;
        right->prev=left;
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        int ret=cache[key]->val;
        remove(key);
        insert(key,ret);
        return ret;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            remove(key);
        }
        if(cache.size()==capacity){
            remove(left->next->key);
        }
        insert(key,value);
    }
};
