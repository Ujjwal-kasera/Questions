class Solution {
public:
    /* we have to find parenthesis such that open bracket = close bracket = n
    * above will also be our base condition and that will one combination of correct parenthesis
    * we have two choose to add ( or ) bracket to string
    * if ( < n then only we can insert it as max ( can be n 
    * if ) < ( then only we can insert it as if ) > ( then it will not be valid parenthesis
    */
    int n;
    vector<string> res;
    void solveBacktrack(string &s,int open,int close){
        if(open==n && close==n){
            res.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            solveBacktrack(s,open+1,close);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            solveBacktrack(s,open,close+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n=n;
        string s;
        solveBacktrack(s,0,0);
        return res;
    }
};