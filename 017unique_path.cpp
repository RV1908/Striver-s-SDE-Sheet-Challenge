class Solution {

    /*//APPROACH ONE(TLE)
    //using recursion
    int countpath(int rn, int cn, int m, int n){
        if(rn>=m || cn>=n){
            return 0;
        }

        if(rn==m-1 && cn==n-1){
            return 1;
        }

        //ya to down jaa sakte h ya to right, dono ka count lo aur store karo
        return (countpath(rn+1, cn, m, n) + countpath(rn, cn+1, m, n));
        
    }

    int uniquePaths(int m, int n) {
        return countpath(0,0,m,n);
    }*/

public:

    //APPROACH TWO
    //combinatrics solution
    //eg; m=3, n=2 --> path = RDD, DRD, DDR
    //m-1 down movement and n-1 right movement
    //hence total path = (m+n-2)comnination(m-1) = (m+n-2)comnination(n-1)

    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int R=m-1;
        double ans=1;

        for(int i=1; i<=R; i++){
            //do not use ans=ans*(N-i+1)/i as it looks same but has different implementation
            ans=ans*(N-R+i)/i;
        }

        return (int)ans;
    }
};
