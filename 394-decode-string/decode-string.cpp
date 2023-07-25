#include<bits/stdc++.h>
class Solution {
public:
    string decodeString(string s) {
        string currStr="";
        string currNum="";
        int prevNum=0;
        string prevStr="";
        int len=s.size();
        stack<string> st;
        for(int i=0;i<len;i++){
            if(isdigit(s[i])){
                currNum+=s[i];
            }
            else if(s[i]=='['){
                st.push(currStr);
                st.push(currNum);
                currStr="";
                currNum="";
            }
            else if(s[i]==']'){
                prevNum=stoi(st.top());
                st.pop();
                prevStr=st.top();
                st.pop();
                while(prevNum--){
                    prevStr+=currStr;
                }
                currStr=prevStr;
            }
            else
                currStr+=s[i];
        }
        return currStr;
    }

    // TC=O(N2)
    // SC=O(N)
    // string decodeString(string s) {
    //     string res="",temp;
    //     string num="";
    //     int n;
    //     char ch;
    //     int len=s.size();
    //     stack<string> st;
    //     for(int i=0;i<len;i++){
    //         temp=s[i];
    //         if(isdigit(s[i])){
    //             num+=s[i];
    //             continue;
    //         }
    //         else if(s[i]=='['){
    //             st.push(num);
    //             num="";
    //             st.push(temp);
    //         }
    //         else if(s[i]==']'){
    //             temp="";
    //             while(st.top()!="["){
    //                 temp+=st.top();
    //                 st.pop();
    //             }
    //             st.pop();
    //             n=stoi(st.top());
    //             st.pop();
    //             res="";
    //             while(n--){
    //                 res+=temp;
    //             }
    //             st.push(res);
    //         }
    //         else
    //             st.push(temp);
    //     }
    //     res="";
    //     while(!st.empty()){
    //         res+=st.top();
    //         st.pop();
    //     }
    //     reverse(res.begin(),res.end());
    //     return res;
    // }
};