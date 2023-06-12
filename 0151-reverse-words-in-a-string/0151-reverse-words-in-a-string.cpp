class Solution {
public:
    string reverseWords(string s) {
        int len=s.size();
        string ans="";
        string temp="";
        stack<char> st;
        st.push(' ');
        for(int i=0;i<len;i++){
            if(s[i]==' ' && st.top()==' ')
                continue;
            st.push(s[i]);
        }
        if(st.top()==' ')
            st.pop();
        while(st.size()>1){
            if(st.top()==' '){
                ans+=temp;
                ans+=" ";
                temp="";
                st.pop();
            }
            else{
                temp=st.top()+temp;
                st.pop();
            }
        }
        ans+=temp;
        return ans;
    }
};