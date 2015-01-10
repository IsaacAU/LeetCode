class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())    return 0;
        int row=grid.size(), col=grid[0].size();
        vector<int> path(grid[0]);
        for(int i=1; i<col; ++i)
            path[i]+=path[i-1];
        for(int i=1; i<row; ++i){
            path[0]+=grid[i][0];
            for(int j=1; j<col; ++j){
                path[j]=grid[i][j]+(path[j-1]<path[j]?path[j-1]:path[j]);
            }
        }
        return path.back();
    }
};
