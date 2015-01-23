class Solution {
public:
    int numDistinct(string S, string T) {
        const int Sn=S.length(), Tn=T.length();
        if(Sn<Tn)   return 0;
        vector<vector<int>> table(Tn, vector<int>(Sn,0));
        if(S[0]==T[0])
            table[0][0]=1;
        for(int i=1; i<Sn; ++i)
            table[0][i]=table[0][i-1]+(S[i]==T[0]?1:0);
        for(int i=1; i<Tn; ++i){
            table[i][i]=(S[i]==T[i]?table[i-1][i-1]:0);
            for(int j=i+1; j<Sn; ++j)
                table[i][j]=table[i][j-1]+(S[j]==T[i]?table[i-1][j-1]:0);
        }
        return table[Tn-1][Sn-1];
    }
};
