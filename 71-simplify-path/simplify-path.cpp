class Solution {
public:
    string simplifyPath(string path) {
        int len=path.size();
        stack<string> st;
        string temp="";
        int count;
        for(int i=0;i<len;i++){
            if(path[i]=='/'){
                if(st.empty() || st.top()!="/"){
                    temp="/";
                }
            }
            else if(path[i]=='.'){
                count=0;
                while(i<len && path[i]!='/'){
                    if(path[i]=='.')
                        count++;
                    temp.push_back(path[i++]);
                }
                i--;
                if(temp.size()==1 && count==1){
                    if(st.size()>1){
                        st.pop();
                    }
                    temp="";
                }
                else if(temp.size()==2 && count==2){
                    if(st.size()>1){
                        st.pop();
                        st.pop();
                    }
                    temp="";
                }
            }
            else{
                while(i<len && path[i]!='/')
                    temp.push_back(path[i++]);
                i--;
            }
            if(temp!=""){
                cout<<temp<<endl;
                st.push(temp);
                temp="";
            }
        }
        temp="";
        if(st.size()>1 && st.top()=="/")
            st.pop();
        while(!st.empty()){
            temp=st.top()+temp;
            st.pop();
        }
        return temp;
    }
};