#include<bits/stdc++.h>
#define debug(x) cout<<#x<<":"<<x<<endl;
using namespace std;
const char lt = '#';
inline string AddLetter(const string& str){
    string ret;
    for(auto i : str){
        ret += lt;
        ret += i;
    }
    ret += lt;
    return ret;
}
inline bool Judge(const int& pos,const int& dis,const int& n){
    return (pos - dis >= 0) && (pos + dis <= n);
}
inline void BF(const int& pos,int& dis,const string& str){
    while(Judge(pos,dis,str.length()-1) && str[pos-dis] == str[pos+dis])++dis;
    return ;
}
inline int Manacher(string& str){
    str = AddLetter(str);
    int l = 0,r = -1,ret = 0;
    vector<int> d(str.length());
    for(int i = 0;i < str.length();i++){
        const int j = l + r - i;
        if(i<=100)cout<<i<<" mirror "<<j<<endl;
        int k;
        if(i > r){//use BF
            k = 1;
        }else{
            k = min(d[j],r-i+1);
        }
        BF(i,k,str);
        d[i] = k - 1;
        ret = max(ret,d[i]);
        if(i + d[i] > r){
            r = i + d[i],l = i - d[i];
        }
    }
    return ret;
}
int main(){
	freopen("P3805_4.in","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string ins;
    cin>>ins;
    cout<<Manacher(ins);
    return 0;
}
