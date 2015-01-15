class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        const int len=s.length();
        bool arr[len];
        fill_n(arr, len, false);
        for(int i=len-1; i>=0; --i){
            for(int j=i+1; j<len; ++j)
                if(arr[j] && dict.count(s.substr(i,j-i))){
                    arr[i]=true;
                    break;
                }
            if(!arr[i] && dict.count(s.substr(i)))
                arr[i]=true;
        }
        return arr[0];
    }
};
