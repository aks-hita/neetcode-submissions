class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x:stones){
            pq.push(x);
        }
        while(pq.size()>1){
            int l=pq.top();
            pq.pop();
            int m=pq.top();
            pq.pop();
            if(l<m) pq.push(m-l);
            else if(l>m) pq.push(l-m);
        }
        return (pq.size()==0)?0:pq.top();
    }
};
