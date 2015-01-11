class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        int table[m+1][n+1];
        fill_n(*table, (m+1)*(n+1), 0);
        for(int i=1; i<m+1; ++i)
            table[i][0]=i;
        for(int i=1; i<n+1; ++i)
            table[0][i]=i;
        for(int i=1; i<m+1; ++i){
            for(int j=1; j<n+1; ++j){
                if(word1[i-1]==word2[j-1])  table[i][j]=table[i-1][j-1];
                else{
                    table[i][j]=1+min(table[i-1][j-1], min(table[i-1][j], table[i][j-1]));
                }
            }
        }
        return table[m][n];
    }
};
