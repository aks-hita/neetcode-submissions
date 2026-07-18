class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()){
            left.push(num);
            return;
        }
        if(num<=left.top()){
            left.push(num);
            if(left.size()>right.size()+1){
                right.push(left.top());
                left.pop();
            }
        }
        else{
            right.push(num);
            if(right.size()>left.size()){
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if(left.size()>right.size()){
            return left.top();
        }
        return ((double)right.top()+left.top())/2.0;
    }
};
