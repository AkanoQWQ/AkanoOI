#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int a,b;
int ExGcd(int a,int b,int& x,int& y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	int gcd = ExGcd(b,a % b,x,y);
	int oldX = x;
	x = y;
	y = oldX - (a/b) * y;
	return gcd;
}
inline int Solve(int a,int b){
	int x,y;
	ExGcd(a,b,x,y);
	int delta = (ceil((1.0f - x) / double(b)));
	return x + delta * b;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b;
	cin>>a>>b;
	cout<<Solve(a,b)<<endl;
	return not(Akano loves pure__Elysia);
}
