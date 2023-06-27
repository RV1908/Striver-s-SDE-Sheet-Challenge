class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<nums.size(); i++){
        
        if(i==0 || (i>0 && nums[i]!=nums[i-1])){
            int a = 0-nums[i];
            int lo=i+1;
            int hi=nums.size()-1;    

            while(hi>lo){
                int b = nums[hi];
                int c = nums[lo];
            
                if(b+c==a){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(b);
                    temp.push_back(c);
                    ans.push_back(temp);
                    while(hi>lo && nums[lo]==nums[lo+1]){
                        lo++;
                    }
                    while(hi>lo && nums[hi]==nums[hi-1]){
                        hi--;
                    }
                    lo++;
                    hi--;
                    
                }
                else if(b+c<a){
                    lo++;
                }
                else{
                    hi--;
                }
            }
        }
        }
        return ans;
    }
};
