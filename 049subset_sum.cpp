void solve(int i, int sum, vector<int> &arr, vector<int> &ans, int n){
        if(i==n){
            ans.push_back(sum);
            return;
        }    
        
        //call for pick
        solve(i+1, sum+arr[i], arr, ans, n);
        
        //call for not pick
        solve(i+1, sum, arr, ans, n);
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        int i=0;
        int sum=0;
        solve(i, sum, arr, ans, n);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
