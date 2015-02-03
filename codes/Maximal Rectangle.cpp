class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res=0;
        if(matrix.empty() || matrix[0].empty()) return res;
        const int m=matrix.size(), n=matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        for(int i=0; i<m; ++i){
            int l=0, r=n;
            for(int j=0; j<n; ++j){
                if(matrix[i][j]=='1'){
                    ++height[j];
                    left[j]=max(left[j], l);
                }else{
                    l=j+1;
                    left[j]=0;  right[j]=n;  height[j]=0;
                }
            }
            for(int j=n-1; j>=0; --j){
                if(matrix[i][j]=='1'){
                    right[j]=min(right[j], r);
                    res=max(res, height[j]*(right[j]-left[j]));
                }else
                    r=j;
            }
        }
        return res;
    }
};
