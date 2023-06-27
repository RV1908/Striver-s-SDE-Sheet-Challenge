//LEETCODE WALA

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int maxi=INT_MIN;
        nums.push_back(0);

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                maxi=max(maxi,cnt);
                cnt=0;
            }
        }

        nums.pop_back();

        return maxi;
    }
};




//CODE STUDIO WALA

int longestSubSeg(vector<int> &arr , int n, int k){
    int cnt0 = 0;
    int maxi=0;

    for(int i=0,j=0; i<n; i++){
        if(arr[i]==0){
            cnt0++;
        }

        while(cnt0>k){
            if(arr[j]==0){
                cnt0--;
            }
            j++;
        }

        maxi = max(maxi, i-j+1);
    }

    return maxi;
}
