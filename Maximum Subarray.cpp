class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum=INT_MIN, cur=INT_MIN;
        for(int i=0; i<n; ++i){
            cur=max(cur, 0)+A[i];
            sum=max(sum, cur);
        }
        return sum;
    }
};
