class Solution {
public:

    bool ispalindrome(string s, int b, int e){
        while(b<=e){
            if(s[b++]!=s[e--]){
                return false;
            }
        }
        return true;
    }

    void solve(int ind, string s, vector<vector<string>> &ans, 
    vector<string>& temp){
        if(ind==s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<s.length(); i++){
            if(ispalindrome(s,ind,i)){
                temp.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, ans, temp);
        return ans;
    }
};
