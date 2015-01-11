class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res;
        sort(begin(S), end(S));
        vector<int> path;
        subset(begin(S), end(S), res, path);
        return res;
    }
private:
    void subset(vector<int>::iterator b, vector<int>::iterator e, vector<vector<int>> &res, vector<int> &path){
        if(b==e){
            res.push_back(path);
            return;
        }
        int cnt=1;
        while(next(b)!=e && *next(b)==*b)   { ++cnt; b=next(b);}
        for(int i=0; i<=cnt; ++i){
            for(int j=0; j<i; ++j)  path.push_back(*b);
            subset(next(b), e, res, path);
            for(int j=0; j<i; ++j)  path.pop_back();
        }
    }
};
