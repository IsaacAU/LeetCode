class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2)    return n;
        int cnt=2, pre1=A[0], pre2=A[1];
        for(int i=2; i<n; ++i){
            int t1=A[i-1];
            if(A[i]!=pre1 || A[i]!=pre2)
                A[cnt++]=A[i];
            pre1=t1; pre2=A[i];
        }
        return cnt;
    }
};
