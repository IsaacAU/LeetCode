class Solution {
public:
    int maxProduct(int A[], int n) {
        int res=A[0], pos=A[0], neg=A[0];
        for(int i=1; i<n; ++i){
            if(A[i]<0)
                swap(pos, neg);
            pos=max(pos*A[i], A[i]);
            neg=min(neg*A[i], A[i]);
            res=max(res, pos);
        }
        return res;
    }
};
