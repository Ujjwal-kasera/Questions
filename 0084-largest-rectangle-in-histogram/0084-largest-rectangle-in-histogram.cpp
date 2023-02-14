class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len=heights.size();
        stack<int> st;
        st.push(-1);
        vector<int> next(len);
        vector<int> prev(len);
        int curr;
        for(int i=len-1;i>=0;i--){
            curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr)
                st.pop();
            next[i]=(st.top()==-1)?len:st.top();
            st.push(i);
        }
        while(st.top()!=-1)
            st.pop();
        for(int i=0;i<len;i++){
            curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr)
                st.pop();
            prev[i]=st.top();
            st.push(i);
        }
        int area=INT_MIN,newArea;
        int l,b;
        for(int i=0;i<len;i++){
            l=heights[i];
            b=next[i]-prev[i]-1;
            newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
};