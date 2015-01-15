class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        function<bool(int,int,int)> search=[&](int pos, int row, int col){
            if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || visit[row][col] || board[row][col]!=word[pos])
                return false;
            if(pos==word.length()-1)    return true;
            visit[row][col]=true;
            bool res=search(pos+1, row-1, col) || search(pos+1, row+1, col) || search(pos+1, row, col-1) || search(pos+1, row, col+1);
            visit[row][col]=false;
            return res;
        };
        for(int i=0; i<board.size(); ++i)
            for(int j=0; j<board[0].size(); ++j)
                if(search(0, i, j))
                    return true;
        return false;
    }
};
