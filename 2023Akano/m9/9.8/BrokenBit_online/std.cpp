#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n,m,ans;
string str;
int main(){
	cout<<"Ask"<<endl;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i & (1<<(j-1))){
				cout<<"Add"<<endl;
				cout<<j<<" "<<i<<endl;
			}
		}
	}
	cout<<"Query"<<endl;
	cin>>str;
	int cnt = 0;
	for(auto i : str){
		ans += (!(i - '0')) * (1<<cnt);
		cnt++;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
