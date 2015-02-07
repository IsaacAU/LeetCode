// method 1
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res=0;
        if(matrix.empty() || matrix[0].empty()) return res;
        const int m=matrix.size(), n=matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        for(int i=0; i<m; ++i){
            int l=0, r=n;
            for(int j=0; j<n; ++j){
                if(matrix[i][j]=='1'){
                    ++height[j];
                    left[j]=max(left[j], l);
                }else{
                    l=j+1;
                    left[j]=0;  right[j]=n;  height[j]=0;
                }
            }
            for(int j=n-1; j>=0; --j){
                if(matrix[i][j]=='1'){
                    right[j]=min(right[j], r);
                    res=max(res, height[j]*(right[j]-left[j]));
                }else
                    r=j;
            }
        }
        return res;
    }
};

// method 2
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())  return 0;
        const int m=matrix.size(), n=matrix[0].size();
        vector<int> hist(n, 0);
        int res=0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(matrix[i][j]=='1')
                    ++hist[j];
                else
                    hist[j]=0;
            }
            res=max(res, maxArea(hist));
        }
        return res;
    }
private:
    int maxArea(vector<int> &hist){
        stack<int> stk;
        hist.push_back(0);
        int res=0;
        for(int i=0; i<hist.size(); ++i){
            while(!stk.empty() && hist[i]<=hist[stk.top()]){
                int h=hist[stk.top()];  stk.pop();
                res=max(res, h*(i-1-(stk.empty()?-1:stk.top())));
            }
            stk.push(i);
        }
        hist.pop_back();
        return res;
    }
};
