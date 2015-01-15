class Solution {
public:
    int search(int A[], int n, int target) {
        int i=0, j=n-1;
        while(i<=j){
            int m=(i+j)/2;
            if(A[i]<=A[m] && A[m]<=A[j]){
                if(target==A[m])   return m;
                else if(target>A[m])    i=m+1;
                else j=m-1;
            }else if(A[i]<=A[m] && A[j]<A[m]){
                if(target==A[i] || target==A[m])    return target==A[i]?i:m;
                else if(target<A[i] || target>A[m]) i=m+1;
                else j=m-1;
            }else{
                if(target==A[m] || target==A[j])    return target==A[m]?m:j;
                else if(target<A[m] || target>A[j]) j=m-1;
                else i=m+1;
            }
        }
        return -1;
    }
};
