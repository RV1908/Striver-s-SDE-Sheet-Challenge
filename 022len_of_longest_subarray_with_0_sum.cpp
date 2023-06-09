int maxLen(vector<int>&A, int n)
    {   
        /*Now let’s say we know that the sum of subarray(i, j) = S, 
        and we also know that the sum of subarray(i, x) = S where i < x < j. 
        We can conclude that the sum of subarray(x+1, j) = 0.

        Let us understand the above statement clearly,

        So in this problem, we’ll store the prefix sum of every element, 
        and if we observe that 2 elements have the same prefix sum, 
        we can conclude that the 2nd part of this subarray sums to zero*/
        
        
        unordered_map<int,int> mp;  //<sum,index at which the sum occured>
        
        int sum=0;
        int maxi=0;
        
        for(int i=0 ;i<n; i++){
            sum+=A[i];
            if(sum==0){
                maxi=max(i+1,maxi);
            }
            
            else if(mp.find(sum)!=mp.end()){
                maxi =max(i-mp[sum],maxi);
            }
            else{
                mp[sum]=i;
            }
        }
        return maxi;
    }
