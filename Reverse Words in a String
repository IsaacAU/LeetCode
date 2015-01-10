class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        string word;
        s.clear();
        while(ss>>word)
            if(s.empty())
                s=word;
            else
                s=word+" "+s;
    }
};
