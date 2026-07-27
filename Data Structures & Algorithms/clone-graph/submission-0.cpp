/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> new_graph;
    Node* dfs(Node* old_add){
        if(old_add==nullptr) return nullptr;
        if(new_graph.count(old_add)) return new_graph[old_add];
        Node* new_add= new Node(old_add->val);
        new_graph[old_add]=new_add;
        for(int i=0;i<old_add->neighbors.size();i++){
            new_add->neighbors.push_back(dfs(old_add->neighbors[i]));
        }
        return new_add;
    }
    Node* cloneGraph(Node* node) {
        new_graph.clear();
        return dfs(node);
    }
};
