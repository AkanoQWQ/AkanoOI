#include<bits/stdc++.h>
using namespace std;
int a,b,c,OBJ,cnt,ans = 1e9;
inline void EXE(int x){
	while(x < OBJ){
		x += 2;
		cnt++;
	}
	while(x > OBJ){
		x--;
		cnt++;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b>>c;
	for(int i = -200;i <= 200;i++){
		OBJ = i;
		cnt = 0;
		EXE(a),EXE(b),EXE(c);
		ans = min(ans,cnt);
	}
	cout<<ans;
	return 0;
}

