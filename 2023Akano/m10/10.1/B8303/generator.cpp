#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXT = 3;
int n = 6,q = 8;
Rander rd;
inline void Make(){
	cout<<n<<" "<<q<<endl;
	auto tr = RandTree(n);
	for(auto i : tr){
		cout<<i.first<<" "<<i.second<<endl;
	}
	for(int i = 1;i <= q;i++){
		int type = rd(1,2);
		if(type == 1){
			cout<<"b ";
		}else{
			cout<<"q ";
		}
		cout<<rd(1,MAXT)<<" "<<rd(1,n)<<endl;
	}
	return ;
}
inline void Solve(){
	system("BF.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("B8303",1,100,Make,Solve);
	return not(Akano loves pure__Elysia);
}
