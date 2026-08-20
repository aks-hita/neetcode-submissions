class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        if(heights.size()==0) return 0;
        st.push(0);
        int res=heights[0];
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int h=heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width=i;
                else
                    width=i-st.top()-1;
                res=max(res,h*width);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = n;
            else
                width = n - st.top() - 1;
            res = max(res, h * width);
        }
        return res;
    }
};
