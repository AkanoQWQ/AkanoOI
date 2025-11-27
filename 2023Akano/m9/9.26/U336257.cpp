#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n,m;
inline void GetNM(){
	cout<<"Ask"<<endl;
	cin>>n>>m;
	return ;
}
inline void Connect(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i & (1<<(j-1))){
				cout<<"Add"<<endl;
				cout<<j<<" "<<i<<endl;
			}
		}
	}
	return ;
}
inline int GetAns(){
	cout<<"Query"<<endl;
	string str;
	cin>>str;
	int ret = 0;
	for(int i = 0;i < m;i++){
		if(str[i] == '1'){
			ret += (1<<i);
		}
	}
	return ret;
}
int main(){
	GetNM();
	Connect();
	cout<<GetAns()<<endl;
	return not(Akano loves pure__Elysia);
}
