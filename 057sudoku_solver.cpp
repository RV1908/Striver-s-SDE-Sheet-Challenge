class Solution {
public:

bool safe(vector<vector<char>>& board, int row, int col, int n){
    for(int i=0; i<9; i++){
        //row check
        if(board[i][col]==(n+'0')){
            return false;
        }
        //col check
        if(board[row][i]==(n+'0')){
            return false;
        }
        //cubic check
        if(board[3*(row/3)+i/3][3*(col/3)+(i%3)]==(n+'0')){
            return false;
        }
    }
    return true;
}

bool Solver(vector<vector<char>>& board) {
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Don't print output and return output as specified in the question
    */
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]=='.'){
                for(int n=1; n<=9; n++){
                    if(safe(board, i, j, n)){
                        board[i][j]=(n+'0');
                        bool hold = Solver(board);
                        if(hold){
                            return true;
                        }
                        else{
                            //backtrack
                            board[i][j]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

    void solveSudoku(vector<vector<char>>& board) {
        Solver(board);
    }
};
