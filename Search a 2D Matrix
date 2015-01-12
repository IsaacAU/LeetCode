class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(target<matrix[0][0]) return false;
        const int m=matrix.size();
        if(m==0)    return false;
        const int n=matrix[0].size();
        int i;
        for(i=0; i<m; ++i){
            if(target==matrix[i][0])    return true;
            if(target>matrix[i][0] && (i==m-1 || target<matrix[i+1][0]))
                break;
        }
        for(int j=1; j<n; ++j)
            if(target==matrix[i][j])    return true;
            else if(target<matrix[i][j])    return false;
        return false;
    }
};
