int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0){
            return 0;
        }

        set<int> copy(arr.begin(), arr.end());

        vector<int> nums(copy.begin(), copy.end());

        sort(nums.begin(), nums.end());

        int ans=1;
        int curr=1;

        for(int i=0; i<nums.size()-1; i++){
            if((nums[i]+1)==nums[i+1]){
                curr++;
            }
            else if((nums[i]+1)!=nums[i+1]){
                curr=1;
            }
            ans=max(ans,curr);
        }

        return ans;
    }
};
