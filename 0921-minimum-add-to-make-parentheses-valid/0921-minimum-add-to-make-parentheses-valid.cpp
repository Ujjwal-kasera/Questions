class Solution {
    /* same logic jo coding ninja ke question ka tha bss usme hm replace 
    krte the to odd number ke string ko neglect kr dete the..pr isme hm odd 
    even dono ko leke chlege usme hm replace krte the to jitne invalid hote 
    the uska half lete the..pr isme hm insert krege to jitne invalid h utne 
    hi insert krege n..islie return a+b krege
    */
public:
    int minAddToMakeValid(string s) {
        int len=s.size();
        stack<char> st;
        char ch;
        for(int i=0;i<len;i++){
            ch=s[i];
            if(ch=='(')
                st.push(ch);
            else{
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else 
                    st.push(ch);
            }
        }
        return st.size();
    }
};