class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i=0, j=1;
        for(; j<n; ++j)
            if(A[j]>A[i])
                A[++i]=A[j];
        return n==0?0:i+1;
    }
};
