class Solution {
public:
    string removeKdigits(string num, int k) {
        int len=num.size();
        stack<char>st;
        char ch;
        for(int i=0;i<len;i++){
            ch=num[i];
            while(k>0 && !st.empty() && st.top()>ch){
                st.pop();
                k--;
            }
            st.push(ch);
            if(st.size() == 1 && ch == '0')
                st.pop();
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        num="";
        while(!st.empty()){
            num+=st.top();
            st.pop();
        }
        reverse(num.begin(),num.end());
        return num==""?"0":num;
    }
};