#include<bits/stdc++.h>
class Solution {
public:
    string decodeString(string s) {
        string res="",temp;
        string num="";
        int n;
        char ch;
        int len=s.size();
        stack<string> st;
        for(int i=0;i<len;i++){
            temp=s[i];
            if(isdigit(s[i])){
                num+=s[i];
                continue;
            }
            else if(s[i]=='['){
                st.push(num);
                num="";
                st.push(temp);
            }
            else if(s[i]==']'){
                temp="";
                while(st.top()!="["){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                n=stoi(st.top());
                st.pop();
                res="";
                while(n--){
                    res+=temp;
                }
                st.push(res);
            }
            else
                st.push(temp);
        }
        res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};