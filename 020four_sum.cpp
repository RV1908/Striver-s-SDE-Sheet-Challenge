vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //APPROACH ONE
        /*set<vector<int>> st;

        set is used to store unique vectors
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){

                we are creating a set that stores nums[k] elements so that we can find the fourth element from that set

                set<long long int> store;
                for(int k=j+1; k<nums.size(); k++){
                    long long sum = nums[i]+nums[j];
                    sum+=+nums[k];
                    long long int fourth = target - (sum);

                    if(store.find(fourth)!=store.end()){
                        vector<int> temp ={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    store.insert(nums[k]);
        
                }
            }
        }

        creating a vector<vector<int>> and storing st in it
        vector<vector<int>> ans(st.begin(), st.end());

        return ans;*/



        //APPROACH TWO
        //without using set

        int n = nums.size();
        vector<vector<int>> ans;

        //sort the array so that we can use the k & l pointers 
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;     //if two adjescent elements are same the continue
            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;       //if two adjescent elements are same the continue
                
                int k=j+1;
                int l = n-1;

                while(k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        //if two adjescent elements are same the k is increased to skip them
                        while(k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                       
                        //if two adjescent elements are same the l is decreased to skip them
                        while(k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                    
                    }                    
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }

        return ans;
    }
