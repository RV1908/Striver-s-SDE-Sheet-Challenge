double myPow(double x, int n) {
        double ans = 1;

        long long nn = n;
        if(n<0){
            nn = abs(n);
        }

        while(nn){   
            //even power hone se agar no ko usi no se multiply karo aur nn/2 kar do
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            //odd power h to x ko ans se multiply karo and nn ko desc karo
            else{      
                ans = ans*x;
                nn = nn-1;
            }
        }

        if(n<0) //agar negative power h to div karo
        {
            ans = (double)(1)/(double)(ans);
        }

        return ans;
    }
