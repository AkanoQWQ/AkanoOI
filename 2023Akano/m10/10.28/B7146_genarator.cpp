#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n = 20,l = 10 + 18 + 11 + 8,maxt = 100;
Rander rd;
inline void Make(){
	int p = rd(0,n);
	cout<<n<<" "<<l<<" "<<p<<endl;
	set<int> st;
	for(int i = 1;i <= n;i++){
		int pos = rd(0,maxt);
		while(st.find(pos) != st.end()){
			pos = rd(0,maxt);
		}
		st.insert(pos);
	}
	for(auto i : st){
		if(rd(0,1)){
			cout<<"+ ";
		}else{
			cout<<"- ";
		}
		cout<<i<<endl;
	}
	return ;
}
inline void Solve(){
	system("B7146_std.exe");
	return ;
}
int main(){
	MakeData("B7146",1,200,Make,Solve);
	return not(Akano loves pure__Elysia);
}
