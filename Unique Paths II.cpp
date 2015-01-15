class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty())    return 0;
        int row=obstacleGrid.size(), col=obstacleGrid[0].size();
        vector<int> path(col, 1);
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(obstacleGrid[i][j]==1)
                    path[j]=0;
                else{
                    if(j>0) path[j] = path[j-1] + (i>0?path[j]:0);
                }
            }
        }
        return path.back();
    }
};
