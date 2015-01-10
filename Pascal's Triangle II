class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return vector<int>{1};
        if(rowIndex==1) return vector<int>{1,1};
        vector<int> v{1,1};
        for(int i=1; i<rowIndex; ++i){
            for(int j=0; j<v.size()-1; ++j)
                v[j]+=v[j+1];
            v.back()=1;
            v.insert(v.begin(), 1);
        }
        return v;
    }
};
