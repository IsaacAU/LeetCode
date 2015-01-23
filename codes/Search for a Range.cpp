class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start=0, end=0, i=0, j=n-1;
        while(i<j){
            int m=(i+j)/2;
            if(A[m]>=target){
                j=m;
            }else{
                i=m+1;
            }
        }
        if(target!=A[i])
            return vector<int>{-1,-1};
        start=i;
        i=0; j=n-1;
        while(i<j){
            int m=(i+j)/2+1;
            if(A[m]>target){
                j=m-1;
            }else{
                i=m;
            }
        }
        end=i;
        return vector<int>{start,end};
    }
};
