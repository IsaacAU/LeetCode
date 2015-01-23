class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        search(s, 0, 4, res, path);
        return move(res);
    }
private:
    void search(const string &s, int cur, int num, vector<string> &res, string &path){
        if(s.length()-cur<num || s.length()-cur>3*num)  return;
        if(cur==s.length() && num==0){
            path.pop_back();
            res.push_back(path);
            path.push_back('.');
            return;
        }
        // 1 digit
        path+=s.substr(cur, 1)+".";   cur+=1;  --num;
        search(s, cur, num, res, path);
        cur-=1;  ++num;  path.erase(path.length()-2, 2);
        // 2 digits
        if(cur+1<s.length() && s[cur]!='0'){
            path+=s.substr(cur, 2)+".";  cur+=2;  --num;
            search(s, cur, num, res, path);
            cur-=2; ++num;  path.erase(path.length()-3, 3);
        }
        // 3 digits
        if(cur+2<s.length()){
            string sub=s.substr(cur, 3);
            int x=stoi(sub);
            if(x<100 || x>255)  return;
            path+=sub+".";  cur+=3;   --num;
            search(s, cur, num, res, path);
            cur-=3;   ++num;    path.erase(path.length()-4, 4);
        }
    }
};
