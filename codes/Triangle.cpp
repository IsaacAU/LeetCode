class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for(int i=1; i<triangle.size(); ++i){
            triangle[i][0]+=triangle[i-1][0];
            for(int j=1; j<triangle[i].size()-1; ++j){
                triangle[i][j]+= triangle[i-1][j-1]<triangle[i-1][j]?triangle[i-1][j-1]:triangle[i-1][j];
            }
            triangle[i].back()+=triangle[i-1].back();
        }
        int res=INT_MAX, sz=triangle.size();
        for(int i=0; i<triangle[sz-1].size(); ++i){
            if(triangle[sz-1][i]<res)
                res=triangle[sz-1][i];
        }
        return res;
    }
};
