class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int start=1;
        for(int i=0; i<=(n-1)/2; ++i)
            fill(res, i, start);
        return move(res);
    }
private:
    void fill(vector<vector<int>> &res, int row, int &start){
        const int n=res.size();
        if(start==n*n){
            res[row][row]=start;
            return;
        }
        int i,j;
        for(j=row; j<n-row-1; ++j)
            res[row][j]=start++;
        for(i=row; i<n-row-1; ++i)
            res[i][n-1-row]=start++;
        for(j=n-1-row; j>row; --j)
            res[n-1-row][j]=start++;
        for(i=n-1-row; i>row; --i)
            res[i][row]=start++;
    }
};
