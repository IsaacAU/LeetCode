class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0)  return res;
        res.push_back(vector<int>{1});
        if(numRows==1)  return res;
        for(int i=1; i<numRows; ++i){
            vector<int> tmp;    tmp.reserve(res.back().size()+1);
            for(int j=0; j<res.back().size(); ++j)
                tmp.push_back(j==0?res.back()[j]:res.back()[j-1]+res.back()[j]);
            tmp.push_back(1);
            res.push_back(move(tmp));
        }
        return move(res);
    }
};
