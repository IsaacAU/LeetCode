class Solution {
public:
    double pow(double x, int n) {
        if(x==0.0 || x==1.0)    return x;
        if(n==0)    return 1;
        long m=n;
        bool neg=false;
        if(m<0){
            neg=true;
            m=-m;
        }
        double res=(m&1)?x:1.0;
        while(m>>=1){
            x*=x;
            if(m&1)
                res*=x;
        }
        return neg?1.0/res:res;
    }
};
