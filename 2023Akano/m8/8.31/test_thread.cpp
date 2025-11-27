#include<bits/stdc++.h>
#include<windows.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
void Print(int x){
	Sleep(x*1000);
	cout<<"Ë¯Ãß "<<x<<" ÃëºóÊä³ö"<<endl;
	return ;
}
int n;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>n){
		thread newthrd(Print,n);
		newthrd.detach();
	}
	return not(Akano loves pure__Elysia);
}

