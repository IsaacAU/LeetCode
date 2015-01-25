class Solution {
public:
    // recursion
    int numTrees(int n) {
        if(n<2) return 1;
        int res=0;
        for(int i=0; i<n; ++i){
            res+=numTrees(i)*numTrees(n-1-i);
        }
        return res;
    }
    // DP
    int numTrees(int n) {
        if(n<=2)    return n;
        vector<int> v(n,0);
        v[0]=1;  v[1]=2;
        for(int i=2; i<n; ++i)
            for(int j=0; j<=i; ++j)
                v[i]+=(j==0?1:v[j-1])*(j==i?1:v[i-1-j]);
        return v.back();
    }
};
