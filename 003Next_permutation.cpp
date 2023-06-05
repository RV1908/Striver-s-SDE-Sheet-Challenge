//in c++ stl there is an inbuilt function (which works like finding a word in the dictionary) 

/*class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};*/

//this inbuilt function finds the next permutation after a given list

//SECOND SOLUTION

    //step1- find the break point in the graph i.e. 
    //find int index (start searching from the end) for which numsa[i]<nums[i+1]
    //we're searching from the end so that we can get the largest prefix match
    
    //step2- searching from end find a no. which is just greater then index value
    //and swap ii with index value
    //we're searching from end bcz after the index val there is a decreasing graph

    //step3- reverse all the numbers from index+1 to the end 
    //so that we get the smallest possibly required number
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }

        for(int i=n-1; i>=index && index!=-1 ; i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1, nums.end());
    }
