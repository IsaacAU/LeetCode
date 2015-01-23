class Solution {
public:
    bool canJump(int A[], int n) {
        int reach=0;
        for(int i=0; i<n; ++i){
            if(i>reach) return false;
            reach=max(reach, A[i]+i);
            if(reach>=n-1)  return true;
        }
    }
};
