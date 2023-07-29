//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int len;
    vector<string> ans;
    bool isSafe(int x,int y,vector<vector<int>>&m,vector<vector<bool>> &visited){
        if(x>=0 && x<len && y>=0 && y<len && m[x][y]==1 && visited[x][y]==0)
            return 1;
        return 0;
    }
    void solve(int x,int y,vector<vector<int>>&m,vector<vector<bool>> &visited,string path){
        if(x==len-1 && y==len-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        
        // Down
        if(isSafe(x+1,y,m,visited)){
            solve(x+1,y,m,visited,path+'D');
        }
        
        // Left
        if(isSafe(x,y-1,m,visited)){
            solve(x,y-1,m,visited,path+'L');
        }
        
        // Right
        if(isSafe(x,y+1,m,visited)){
            solve(x,y+1,m,visited,path+'R');
        }
        
        // Upward
        if(isSafe(x-1,y,m,visited)){
            solve(x-1,y,m,visited,path+'U');
        }
        visited[x][y]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        len=n;
        if(m[0][0]==0)
            return ans;
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        solve(0,0,m,visited,"");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends