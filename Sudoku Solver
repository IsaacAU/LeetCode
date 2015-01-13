class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        search(board);
    }
private:
    bool valid(vector<vector<char>> &board, int i, int j){
        for(int x=0; x<9; ++x)
            if(x!=i && board[x][j]==board[i][j])
                return false;
        for(int y=0; y<9; ++y)
            if(y!=j && board[i][y]==board[i][j])
                return false;
        for(int x=i/3*3; x<(i/3+1)*3; ++x)
            for(int y=j/3*3; y<(j/3+1)*3; ++y)
                if(x!=i && y!=j && board[x][y]==board[i][j])
                    return false;
        return true;
    }
    bool search(vector<vector<char>> &board){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j]!='.')    continue;
                for(char c='1'; c<='9'; ++c){
                    board[i][j]=c;
                    if(valid(board, i, j) && search(board))
                        return true;
                }
                board[i][j]='.';
                return false;
            }
        }
        return true;
    }
};
