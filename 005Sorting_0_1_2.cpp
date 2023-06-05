void sortColors(vector<int>& nums) {

        //APPROACH ONE :)
        /*sort(nums.begin(), nums.end());*/


        //APPROACH TWO
        /*int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]==0)  
                cnt0++;

            else if(nums[i]==1)
                cnt1++;

            else
                cnt2++;
        }

        for(int i=0; i<cnt0; i++){
            nums[i]=0;
        }

        for(int i=cnt0; i<cnt0+cnt1; i++){
            nums[i]=1;
        }

        for(int i=cnt0+cnt1; i<cnt0+cnt1+cnt2; i++){
            nums[i]=2;
        }*/


        

        //APPROACH THREE
        int n = nums.size();
        int low=0;
        int mid=0;
        int high = n-1;

        while(mid<=high){
            if (nums[mid]==0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }

            else if(nums[mid]==1){
                mid++;
            }

            //if(nums[mid]==2)
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
