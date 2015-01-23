class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)  return 0;
        bool neg=false;
        if(x<0){
            neg=true;
            x=-x;
        }
        int res=0;
        while(x){
            if(res>INT_MAX/10 || res==INT_MAX/10 && x%10>=INT_MAX%10)   return 0;
            res=10*res+x%10;
            x/=10;
        }
        return neg?-res:res;
    }
};
