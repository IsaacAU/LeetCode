class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        map<int, int> m;
        for(auto i:num)
            m[i]++;
        vector<vector<int>> res;
        vector<int> path;
        search(begin(m), end(m), target, res, path, 0);
        return move(res);
    }
private:
    void search(map<int,int>::iterator b, map<int,int>::iterator e, int target, vector<vector<int>> &res, vector<int> &path, int cur){
        if(cur==target){
            res.push_back(path);
            return;
        }
        if(cur>target || b==e)  return;
        search(next(b), e, target, res, path, cur);
        for(int i=1; i<=b->second; ++i){
            if(cur+i*b->first>target)   break;
            for(int j=0; j<i; ++j)  path.push_back(b->first);   cur+=i*b->first;
            search(next(b), e, target, res, path, cur);
            for(int j=0; j<i; ++j)  path.pop_back();    cur-=i*b->first;
        }
    }
};
