#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
Rander rd;
inline void Make(){
	int n = 4e5,q = 4e5,val = 1000;
	cout<<n<<" "<<q<<endl;
	for(int i = 1;i <= n;i++){
		cout<<rd(1,val)<<" ";
	}
	cout<<endl;
	for(int i = 2;i <= n;i++){
		cout<<rd(1,i-1)<<" ";
	}
	cout<<endl;
	for(int i = 1;i <= q;i++){
		int opt = rd(1,3);
		if(opt == 1){
			cout<<rd(1,n)<<" "<<rd(1,sqrt(n))<<" "<<rd(1,val)<<endl;
		}else if(opt == 2){
			cout<<rd(1,n)<<" "<<rd(1,sqrt(n))<<endl;
		}else if(opt == 3){
			n++;
			cout<<rd(1,n-1)<<" "<<rd(1,val)<<endl;
		}
	}
	return ;
}
inline void Solve(){}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("tree",1,1,Make,Solve);
	return not(Akano loves pure__Elysia);
}
