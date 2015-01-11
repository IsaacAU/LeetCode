class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(begin(S), end(S));
        vector<vector<int>> res;
        vector<int> path;
        DFS(begin(S), end(S), res, path);
        return move(res);
    }
private:
    void DFS(vector<int>::iterator b, vector<int>::iterator e, vector<vector<int>> &res, vector<int> &path){
        if(b==e){
            res.push_back(path);
            return;
        }
        DFS(next(b), e, res, path);
        path.push_back(*b);
        DFS(next(b), e, res, path);
        path.pop_back();
    }
};
