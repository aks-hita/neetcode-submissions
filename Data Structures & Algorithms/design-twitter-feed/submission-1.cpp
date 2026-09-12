class Node{
    public:
    int userId;
    int tweetId;
    int time;
    Node* next=nullptr;
    Node(){}
    Node(int userId, int tweetId, int time){
        this->userId=userId;
        this->tweetId=tweetId;
        this->time=time;
    }
};
class Twitter {
public:
    int time=0;
    unordered_map<int, Node*> latest;
    unordered_map<int, vector<int>> following; //if x follows y, follow[x]={y}
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        Node* new_tweet = new Node(userId, tweetId, time);
        if(latest.find(userId)==latest.end()){
            latest[userId]= new_tweet;
        }
        else{
            Node* temp = latest[userId];
            latest[userId]=new_tweet;
            new_tweet->next=temp;
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<pair<int,Node*>> pq;
        if(latest.find(userId)!=latest.end())
            pq.push({latest[userId]->time,latest[userId]});
        int i=0;
        if(following[userId].size()>0){
            for(int u:following[userId]){
                if(latest.find(u)!=latest.end())
                    pq.push({latest[u]->time,latest[u]});
            }
        }
        while(i<10 && !pq.empty()){
            auto it=pq.top();
            feed.push_back(it.second->tweetId);
            pq.pop();
            if(it.second->next!=nullptr) pq.push({it.second->next->time,it.second->next});
            i++;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        auto it = find(following[followerId].begin(),following[followerId].end(),followeeId);
        if(it == following[followerId].end()) {
            following[followerId].push_back(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = find(following[followerId].begin(),
            following[followerId].end(),
            followeeId);if (it != following[followerId].end())following[followerId].erase(it);
    }
};
