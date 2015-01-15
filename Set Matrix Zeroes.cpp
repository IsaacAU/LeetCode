class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty())  return;
        bool firstRow=false, firstCol=false;
        int i,j, m=matrix.size(), n=matrix[0].size();
        for(i=0; i<m; ++i)
            if(matrix[i][0]==0) 
                firstCol=true;
        for(j=0; j<n; ++j)
            if(matrix[0][j]==0) 
                firstRow=true;
        for(i=1; i<m; ++i)
            for(j=1; j<n; ++j)
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
        for(i=1; i<m; ++i)
            for(j=1; j<n; ++j)
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j]=0;
        if(firstRow)
            for(j=0; j<n; ++j)
                matrix[0][j]=0;
        if(firstCol)
            for(i=0; i<m; ++i)
                matrix[i][0]=0;
    }
};
