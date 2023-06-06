bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //APPROACH ONE(BRUTE FORCE)
    /*int n= matrix.size();
    int m=matrix[0].size();

    bool ans = false;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==target){
                ans=true;
            }
        }
    }       

    return ans;
    }*/

        

        //APPROACH TWO
        //since sorted array is given hence binary search can be used

        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row*col-1;

        int mid = start+(end-start)/2;
        while(start<=end){
            int element = matrix[mid/col][mid%col];
            if(element==target){
                return 1;
            }
            if(element<target){
                start = mid+1;
            }
            if(element>target){
                end = mid-1;
            }
            mid = start+(end-start)/2;
            
        }
        return 0;
    }
