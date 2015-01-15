class Solution {
public:
    int trap(int A[], int n) {
        if(n<3)    return 0;
        vector<int> left(n,0), right(n,0);
        int i;
        left[0]=A[0];
        for(i=1; i<n; ++i)
            left[i]=max(left[i-1], A[i]);
        right[n-1]=A[n-1];
        for(i=n-2; i>=0; --i)
            right[i]=max(right[i+1], A[i]);
        int res=0;
        for(i=0; i<n; ++i)
            res+=min(left[i], right[i])-A[i];
        return res;
    }
};
