class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.empty()) return 0;
        int row=dungeon.size(), col=dungeon[0].size();
        dungeon[row-1][col-1]=1-dungeon[row-1][col-1];
        for(int i=row-2; i>=0; --i){
            dungeon[i][col-1]=max(1,dungeon[i+1][col-1])-dungeon[i][col-1];
        }
        for(int j=col-2; j>=0; --j){
            dungeon[row-1][j]=max(1,dungeon[row-1][j+1])-dungeon[row-1][j];
        }
        for(int i=row-2; i>=0; --i){
            for(int j=col-2; j>=0; --j){
                int right=max(1,dungeon[i][j+1])-dungeon[i][j];
                int down=max(1,dungeon[i+1][j])-dungeon[i][j];
                dungeon[i][j]=min(right, down);
            }
        }
        return max(1, dungeon[0][0]);
    }
};
