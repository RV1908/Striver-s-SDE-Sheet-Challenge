class Solution {
public:

    void solve(vector<int> base, vector<int> &v){
        int n=v.size();
        int maxi =base[0];
        for(int i=0; i<n; i++){
            if(base[i]>maxi){
                maxi=base[i];
            }
            v[i]=maxi;
        }
    }


    //APPROACH ONE
    /*int trap(vector<int>& height) {
        int n=height.size();

        vector<int> pref(n);
        vector<int> suff(n);

        vector<int> forpre(height.begin(), height.end());
        reverse(height.begin(), height.end());
        vector<int> forsuff(height.begin(), height.end());
        reverse(height.begin(), height.end());

        solve(forpre, pref);
        solve(forsuff, suff);

        reverse(suff.begin(), suff.end());

        //at this point pref is storing height of the right side
        //and suff is storing height of left side for each value

        //height - 0 1 0 2 1 0 1 3 2 1 2 1
        //pref   - 0 1 1 2 2 2 2 3 3 3 3 3
        //suff   - 3 3 3 3 3 3 3 3 2 2 2 1

        //min of pref and suff will give the probable storage capacity
        //subrtracting height from this value will give the exact storage capacity
        int water = 0;
        for(int i=0; i<n; i++){
            water+=(min(pref[i],suff[i])-height[i]);
        }

        return water;
    }*/



    //OPTIMAL SOLUTION
    int trap(vector < int > & height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int maxLeft = 0, maxRight = 0;
        while (left <= right) {

            //above we used  ==>  water+=(min(pref[i],suff[i])-height[i])
            //meaning we seek the min of left, right

            if (height[left] <= height[right]) {        //left is min
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    res += maxLeft - height[left];
                }
                left++;
                }

            else {
                if (height[right] >= maxRight) {        //right is min
                    maxRight = height[right];
                } else {
                    res += maxRight - height[right];
                }
                right--;
            }
        }
        return res;
    }
};
