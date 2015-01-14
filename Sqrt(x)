class Solution {
public:
    int sqrt(int x) {
        if(x<2) return x;
        long long i=1, j=x;
        while(i<j){
            long long m=(i+j)/2;
            if(m*m<=x && (m+1)*(m+1)>x)    return m;
            else if(m*m>x)    j=m;
            else    i=m;
        }
        return i;
    }
};
