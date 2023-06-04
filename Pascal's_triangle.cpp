    //this function basically works like row Combination col i.e. rCc 
    //but in an optimised way
    //for both row and col 0 based indexing is used
    //example - let row =5
    // 1 5 10 10 5 1
    //first ele is 1 and from second to last element 
    //1  5/1  5*4/1*2  5*4*3/1*2*3  5*4*3*2/1*2*3*4  5*4*3*2*1/1*2*3*4*5

    vector<int> getrow(int row){
        vector<int> temp;
        int res=1;
        
        temp.push_back(res);
            
        if(row==0){
            return temp;
        }

        for(int i=1; i<=row; i++){
            res=res*(row+1-i);
            res=res/i;
            temp.push_back(res);
        }
        
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=0; i<numRows; i++){
            vector<int> temp = getrow(i);
            ans.push_back(temp);
        }

        return ans;
    }
