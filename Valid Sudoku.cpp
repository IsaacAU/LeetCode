class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> col(9, 0), block(3, 0);
        int row=0;
        for(int i=0; i<9; ++i){
            row=0;
            if(i%3==0)
                fill(begin(block), end(block), 0);
            for(int j=0; j<9; ++j){
                if(board[i][j]=='.')    continue;
                int x=int(board[i][j]-'1');
                if(row & 1<<x || col[j] & 1<<x || block[j/3] & 1<<x)    return false;
                row|=1<<x;     // each row
                col[j]|=1<<x;  // each column
                block[j/3]|=1<<x; // each block
            }
        }
        return true;
    }
};
