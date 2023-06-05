void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();    //size of row
        int m = matrix[0].size();   //size of column
        
        //saving dummy rows and columns
        vector<int> row(n,-1);      
        vector<int> col(m,-1);
        
        //marking dummy rows and column
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }

        //making elements zero of marked rows and columns
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i]==0 || col[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
