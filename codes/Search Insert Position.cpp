class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i=0, j=n;
        while(i<j){
            int m=(i+j)/2;
            if(target==A[m])    return m;
            if(target>A[m])
                i=m+1;
            else
                j=m;
        }
        return i;
    }
};
