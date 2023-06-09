int subarraysXor(vector<int> &A, int B)
{
    int n=A.size();
    int cnt=0;
        
    for(int i=0; i<n; i++){
        int xorr=0;
        for(int j=i; j<n; j++){
            xorr=A[j]^xorr;
            if(xorr==B){
                cnt++;
            }
        }
    }
    return cnt;
}
