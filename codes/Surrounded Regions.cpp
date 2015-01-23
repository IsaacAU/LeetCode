class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty())   return;
        const int m=board.size(), n=board[0].size();
        function<void(int,int)> search=[&](int i, int j){
            if(board[i][j]!='O') return;
            board[i][j]='Y';
            if(i>0)     search(i-1,j);
            if(i<m-1)   search(i+1,j);
            if(j>1)     search(i,j-1);
            if(j<n-2)   search(i,j+1);
        };
        int i,j;
        for(i=0; i<m; ++i){
            search(i,0);
            search(i,n-1);
        }
        for(j=0; j<n; ++j){
            search(0,j);
            search(m-1,j);
        }
        for(i=0; i<m; ++i)
            for(j=0; j<n; ++j)
                if(board[i][j]=='Y')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
    }
};
