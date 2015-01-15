class Solution {
public:
    void sortColors(int A[], int n) {
        int zero=0, one=0;
        int i=0;
        while(i<n){
            if(A[i]==0){
                if(i>zero)
                    swap(A[i], A[zero]);
                else
                    ++i;
                ++zero;
                if(one<zero)    one=zero;
            }else if(A[i]==1){
                if(i>one)
                    swap(A[i], A[one]);
                else
                    ++i;
                ++one;
            }else
                ++i;
        }
    }
};
