class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int y=x,z=0;
        while(y){
            z=10*z+y%10;
            y/=10;
        }
        return x==z;
    }
};
