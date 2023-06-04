int maxProfit(vector<int>& prices) {

        //APPROACH ONE(TLE)
        /*int n = prices.size();
        int profit = 0;

        for(int i=0 ; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(prices[i]<prices[j]){
                    int temp = prices[j]-prices[i];
                    profit = max(temp, profit);
                }
            }
        }

        return profit;*/



        //APPROACH TWO
        int minprice = INT_MAX;
        int maxprofit = 0;
        int n = prices.size();

        for(int i=0; i<n; i++){
            minprice = min(minprice, prices[i]);
            maxprofit = max(maxprofit, prices[i]-minprice);
        }

        return maxprofit;
