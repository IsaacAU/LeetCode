class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int pre=1, cur=2, next;
        for(int i=3; i<=n; ++i){
            next=pre+cur;
            pre=cur;
            cur=next;
        }
        return cur;
    }
};
