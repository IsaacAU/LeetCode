class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> stk;
        int res=0;
        for(int i=0; i<height.size(); ++i){
            while(!stk.empty() && height[stk.top()]>=height[i]){
                int t=stk.top();  stk.pop();
                int area = height[t]*(stk.empty()?i:i-stk.top()-1);
                if(area>res)    res=area;
            }
            stk.push(i);
        }
        return res;
    }
};
