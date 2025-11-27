#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
string s;
inline string PreCalc(const string& str){
	string ret = "#";
	for(auto i : str){
		ret += i;
		ret += "#";
	}
	return ret;
}
inline bool Judge(const int& pos,const int& now,const int& n){
	return (pos - now >= 0) && (pos + now <= n);
}
inline int BF(const int& pos,int now,const string& str){
	while(Judge(pos,now,str.length()-1) && str[pos-now] == str[pos+now])++now;
	return --now;
}
inline int Manacher(const string& str){
	int l = 0,r = -1,ret = 0,len = str.length();
	vi d(len);
	for(int i = 0;i < len;i++){
		int k = BF(i,0,str);
		cout<<i<<" BF GET "<<k<<endl;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;
	s = PreCalc(s);
	cout<<Manacher(s); 
	return 0;
}
