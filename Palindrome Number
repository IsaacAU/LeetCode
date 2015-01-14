class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n=0, y=x;
        while(y){
            y/=10;
            ++n;
        }
        y=pow(10,n-1);
        while(x){
            if(x/y!=x%10)  return false;
            x%=y;
            x/=10;
            y/=100;
        }
        return true;
    }
};
