void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int> ans(m+n);
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                ans[k]=nums1[i];
                k++;
                i++;
            }
            else{
                ans[k]=nums2[j];
                k++;
                j++;
            }
        }
        while(i<m){
            ans[k]=nums1[i];
            k++;
            i++;
        }
        while(j<n){
            ans[k]=nums2[j];
            k++;
            j++;
        }

        //coping value of ans in nums1
        for(int i=0; i<m+n; i++){
            nums1[i]=ans[i];
        }
         
    }
