class Solution {
public:
    int jump(int A[], int n) {
        if(n<2) return 0;
        if(A[0]>=n-1)   return 1;
        int cnt=0, cur=-1, next=A[0];
        for(int i=0; i<n; ++i){
            if(i>cur){
                ++cnt;
                cur=next;
            }
            next=max(next, i+A[i]);
            if(next>=n-1)   return cnt+1;
        }
    }
};
