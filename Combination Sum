class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(begin(candidates), end(candidates));
        search(begin(candidates), end(candidates), target, res, path);
        return move(res);
    }
private:
    void search(vector<int>::iterator b, vector<int>::iterator e, int target, vector<vector<int>> &res, vector<int> &path){
        if(target==0){
            res.push_back(path);
            return;
        }
        if(b==e)    return;
        int i=0, j;
        while(target>=i*(*b)){
            for(j=0; j<i; ++j)  path.push_back(*b);
            search(next(b), e, target-i*(*b), res, path);
            for(j=0; j<i; ++j)  path.pop_back();
            ++i;
        }
    }
};
