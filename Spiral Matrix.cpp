class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.empty())  return res;
        const int m=matrix.size(), n=matrix[0].size();
        res.reserve(m*n);
        int i=0,j=0;
        while(i<=(m-1)/2 && j<=(n-1)/2)
            fill(matrix, i++, j++, res);
        return move(res);
    }
private:
    void fill(vector<vector<int>> &matrix, int row, int col, vector<int> &res){
        const int m=matrix.size(), n=matrix[0].size();
        int i,j;
        if(row==m-row-1){
            for(j=col; j<n-col; ++j)
                res.push_back(matrix[row][j]);
        }else if(col==n-col-1){
            for(i=row; i<m-row; ++i)
                res.push_back(matrix[i][col]);
        }else{
            for(j=col; j<n-col-1; ++j)
                res.push_back(matrix[row][j]);
            for(i=row; i<m-row-1; ++i)
                res.push_back(matrix[i][n-col-1]);
            for(j=n-col-1; j>col; --j)
                res.push_back(matrix[m-row-1][j]);
            for(i=m-row-1; i>row; --i)
                res.push_back(matrix[i][col]);
        }
    }
};
