#include<bits/stdc++.h>
#include<AL/datamaker.h>
using namespace std;
inline void Make(){
	Rander rd(1,INT_MAX / 2);
	cout<<rd()<<" "<<rd()<<endl;
	return ;
}
inline void Solve(){
	int a,b;
	cin>>a>>b;
	cout<<a+b<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("ab",1,100,Make,Solve);
	return 0;
}
