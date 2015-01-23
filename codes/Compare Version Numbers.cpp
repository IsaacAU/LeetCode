class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        string s1,s2;
        while(!ss1.eof() || !ss2.eof()){
            int i1=0,i2=0;
            if(!ss1.eof()){
                getline(ss1,s1,'.');
                i1=stoi(s1);
            }
            if(!ss2.eof()){
                getline(ss2,s2,'.');
                i2=stoi(s2);
            }
            if(i1>i2)
                return 1;
            else if(i1<i2)
                return -1;
        }
        return 0;
    }
};
