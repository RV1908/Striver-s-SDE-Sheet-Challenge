int maxSubArray(vector<int>& nums) {

        //APPROACH ONE(BRUTE FORCE)
        /*int maxi = INT_MIN;
        int n=nums.size();
        //i&j will create all possible sub arrays
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int sum=0;

                for(int k=i; k<=j; k++){
                    sum+=nums[k];
                }
                //amongst sum of all subarrays, maximum sum is stored
                maxi = max(maxi,sum);
            }
        }

        return maxi;*/


        //APPROACH TWO
        /*int maxi = INT_MIN;
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                maxi = max(sum,maxi);
            }
        }
        return maxi;*/




        //BEST APPROACH
        int maxi = INT_MIN;
        int n=nums.size();
        int sum =0;
        
        for(int i=0; i<n; i++){
            sum+=nums[i];

            if(sum>maxi){
                maxi=max(sum,maxi);
            }

            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
