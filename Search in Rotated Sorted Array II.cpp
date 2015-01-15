class Solution {
public:
    bool search(int A[], int n, int target) {
        int i=0, j=n-1;
        while(i<=j){
            while(i<n-1 && A[i]==A[i+1])    ++i;
            while(j>0 && A[j]==A[j-1])  --j;
            if(i>=j)    return target==A[i];
            int m=(i+j)/2;
            if(target==A[m])    return true;
            if(A[i]<=A[m] && A[m]<=A[j]){
                if(target<A[m]) j=m-1;
                else    i=m+1;
            }else if(A[i]<=A[m] && A[m]>A[j]){
                if(target>=A[i] && target<A[m]) j=m-1;
                else    i=m+1;
            }else{
                if(target>A[m] && target<=A[j]) i=m+1;
                else j=m-1;
            }
        }
        return false;
    }
};
