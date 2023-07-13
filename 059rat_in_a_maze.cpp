#include <bits/stdc++.h> 

bool safe(int x, int y, int n,vector<vector<bool>> &vis,vector < vector < int >> & arr){
    if((x>=0 && x<n)&&(y>=0 && y<n)&& arr[y][x]==1 && vis[y][x]!=1){
        return true;
    }
    else{
        return false;
    }
    
}

void solve(int x, int y,vector < vector < int >> & arr, int n, vector<string>& ans, 
        vector<vector<bool>> &vis,string path){
            if(x==n-1 && y==n-1){
                ans.push_back(path);
                return;
            } 

            vis[y][x]=true;
            //D,L,R,U
            //down = x=x, y=y+1
            if(safe(x, y+1, n, vis, arr)){
                //path.push_back('D');
                solve(x,y+1,arr, n, ans, vis, path+'D');
                //path.pop_back();
            }
            //left = x=x-1, y=y
            if(safe(x-1, y, n, vis, arr)){
                //path.push_back('L');
                solve(x-1, y,arr, n, ans, vis, path+'L');
                //path.pop_back();
            }
            //right = x=x+1, y=y
            if(safe(x+1, y, n, vis, arr)){
                //path.push_back('R');
                solve(x+1, y,arr, n, ans, vis, path+'R');
                //path.pop_back();
            }
            //down = x=x, y=y-1
            if(safe(x, y-1, n, vis, arr)){
                //path.push_back('D');
                solve(x,y-1,arr, n, ans, vis, path+'U');
                //path.pop_back();
            }

            //backtracking
            vis[y][x]=false;
    }

vector<string> ratMaze(vector<vector<int>> &mat) {
    // Write your code here.
    int n = mat.size();
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n,false));
    string path = "";

    if(mat[0][0]==0){
        return ans;
    }

    //y=row, x=col
    int x=0; int y=0;
    solve(x,y,mat, n, ans, vis, path);
    
    return ans;

}
