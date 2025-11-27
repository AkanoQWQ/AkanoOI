#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
inline void Make(){
	static int no = 0;
	no++;
	cout<<no<<endl;
	return ;
}
inline void Solve(){
	cout<<"Hello world!"<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("test",1,4,Make,Solve);
	return not(Akano loves pure__Elysia);
}
