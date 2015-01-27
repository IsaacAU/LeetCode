#include<iostream>
#include<cstdio>

using namespace std;

class Solution{
public:
    Solution(const char *file){
        freopen(file, "r", stdin);
        cin.sync_with_stdio(0);
        cin.tie(0);
    }
    int read(char *buf, int n){
        int k=n/4, i=0, x;
        for(; i<k; ++i){
            x=read4(buf+4*i);
            if(x<4) return 4*i+x;
        }
        if(n%4==0)  return 4*i;
        x=read4(backup);
        for(int j=0; j<min(x,n%4); ++j)
            buf[4*i+j]=backup[j];
        return 4*i+min(x,n%4);
    }
    int read4(char *buf){
        int n=0;
        while(cin.get(buf[n]) && ++n<4);
        return n;
    }
private:
    char backup[4];
};

int main(){
    Solution s("input.txt");
    int n=10;
    char *buf=new char[n];
    int x=s.read(buf, n);
    cout<<x<<endl;
    cout<<buf<<endl;
    x=s.read(buf, n);
    cout<<x<<endl;
    cout<<buf<<endl;
    delete []buf;
}
