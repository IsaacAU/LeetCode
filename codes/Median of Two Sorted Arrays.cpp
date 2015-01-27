class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2)
            return findKth(A, m, B, n, (m+n)/2+1);
        else
            return (findKth(A, m, B, n, (m+n)/2)+findKth(A, m, B, n, (m+n)/2+1))/2.0;
    }
private:
    int findKth(int A[], int m, int B[], int n, int k){
        if(m==0)    return B[k-1];
        if(n==0)    return A[k-1];
        if(k==1)    return min(A[0], B[0]);
        int i=min(m, k/2), j=min(n, k/2);
        if(A[i-1]>B[j-1])
            return findKth(A, m, B+j, n-j, k-j);
        else
            return findKth(A+i, m-i, B, n, k-i);
    }
};
