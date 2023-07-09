class Solution {
public:

    void solve(int index, vector<int>& candidates, vector<vector<int>> &ans, 
    vector<int> &temp, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
       

        //pick
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }

            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                solve(i+1, candidates, ans, temp, target-candidates[i]);
                temp.pop_back();
            }
            else{
                break;
            }
        }
        //not pick is not being used because we have to pick a value from sorted array of candidates
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> res;

        solve(0, candidates, res, temp, target);

        return res;
    }
};
