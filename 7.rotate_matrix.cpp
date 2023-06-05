void rotate(vector<vector<int>>& matrix) {
        //APPROACH ONE
        /*int row=matrix.size();
        int col=matrix[0].size();

        //create a new matrix
        vector<vector<int>> newmat(row, vector<int>(row,0));

        //copy first row of original matrix to last col of new matrix
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                newmat[j][row-i-1] = matrix[i][j];
            }
        }

        for(int i=0; i<row ; i++){
            for(int j=0; j<col; j++){
                matrix[i][j]=newmat[i][j];
            }
        }*/



        //APPROACH TWO
        //first take transpose of the matrix
        //then reverse each row

        int n = matrix.size();
        for(int i=0; i<n; i++){

            //j starts from zero and goes till i so that the transpose of transpose is not made
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
