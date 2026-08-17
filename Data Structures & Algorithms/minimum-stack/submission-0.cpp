class MinStack {
public:
    stack<int> nums;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int val) {
        if(nums.empty()){
            nums.push(val);
            mins.push(val);
            return;
        }
        nums.push(val);
        if(val<mins.top()) mins.push(val);
        else mins.push(mins.top());
    }
    
    void pop() {
        nums.pop();
        mins.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
