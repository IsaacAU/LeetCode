class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> path;
        vector<vector<string>> res;
        search(res, path, n);
        return move(res);
    }
private:
    bool valid(vector<int> &path){
        const int n=path.size()-1;
        for(int i=0; i<n; ++i)
            if(path[i]==path[n] || abs(path[i]-path[n])==n-i)
                return false;
        return true;
    }
    void search(vector<vector<string>> &res, vector<int> &path, int n){
        if(path.size()==n){
            vector<string> tmp;
            for(int i=0; i<n; ++i){
                string s(n, '.');
                s[path[i]]='Q';
                tmp.push_back(move(s));
            }
            res.push_back(move(tmp));
            return;
        }
        for(int i=0; i<n; ++i){
            path.push_back(i);
            if(valid(path))
                search(res, path, n);
            path.pop_back();
        }
    }
};
