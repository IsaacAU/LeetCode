class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length(), n=s2.length();
        if(s3.length()!=m+n)    return false;
        bool table[m+1][n+1];
        fill_n(*table, (m+1)*(n+1), false);
        table[0][0]=true;
        for(int i=1; i<n+1; ++i)
            table[0][i]=table[0][i-1]&&s3[i-1]==s2[i-1];
        for(int i=1; i<m+1; ++i)
            table[i][0]=table[i-1][0]&&s3[i-1]==s1[i-1];
        for(int i=1; i<m+1; ++i){
            for(int j=1; j<n+1; ++j){
                table[i][j]=table[i-1][j]&&s3[i+j-1]==s1[i-1] || table[i][j-1]&&s3[i+j-1]==s2[j-1];
            }
        }
        return table[m][n];
    }
};
