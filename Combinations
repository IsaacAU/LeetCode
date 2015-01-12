class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> lib;    lib.reserve(n);
        for(int i=1; i<=n; ++i) lib.push_back(i);
        vector<vector<int>> res;
        vector<int> path;
        search(begin(lib), end(lib), res, path, k);
        return move(res);
    }
private:
    void search(vector<int>::iterator b, vector<int>::iterator e, vector<vector<int>> &res, vector<int> &path, int k){
        if(path.size()==k){
            res.push_back(path);
            return;
        }
        if(b==e)    return;
        search(next(b), e, res, path, k);
        path.push_back(*b);
        search(next(b), e, res, path, k);
        path.pop_back();
    }
};
