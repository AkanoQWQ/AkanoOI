#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
int n = 5000;
int cnt = 0;
inline void Make(){
	++cnt;
	if(cnt <= 3){
		n = 6;
	}else if(cnt <= 5){
		n = 20;
	}else if(cnt <= 10){
		n = 100;
	}else if(cnt <= 15){
		n = 1000;
	}else{
		n = 5000;
	}
	auto mp = RandTree(n);
	cout<<n<<endl;
	for(auto i : mp)cout<<i.first<<" "<<i.second<<endl;
	return ;
}
inline void Solve(){
	system("voltis.exe");
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("voltis",1,20,Make,Solve);
	return 0;
}

