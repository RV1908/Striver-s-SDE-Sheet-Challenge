class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> res;
        for(int i=0; i<nums.size(); i++){
            res.insert(nums[i]);
        }

        vector<int> temp;
        for(auto it: res){
            temp.push_back(it);
        }

        int n = temp.size();
         
        for(int  i=0; i<n; i++){
            nums[i]=temp[i];
        }

        return n;
    }
};
