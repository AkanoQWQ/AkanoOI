#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
int n,k;
Rander rd;
inline void Make1(){
	n = 4005,k = rd(1,15);
	cout<<n<<" "<<k<<endl;
	int rt = rd(1,n);
	for(int i = 1;i <= n;i++){
		if(i == rt)continue;
		cout<<rt<<" "<<i<<" "<<" "<<rd(1,20)<<endl;
	}
	return ;
}
inline void Make2(){
	n = 100,k = rd(1,n);
	auto mp = RandTree(n);
	cout<<n<<" "<<k<<endl;
	for(auto i : mp){
		cout<<i.first<<" "<<i.second<<" "<<rd(1,n)<<endl;
	}
	return ;
}
inline void Make3(){
	n = 2000,k = rd(1,10);
	auto mp = RandTree(n);
	cout<<n<<" "<<k<<endl;
	for(int i = 1;i < n;i++){
		cout<<i<<" "<<i+1<<" "<<rd(1,20)<<endl;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("route4.in","w",stdout);
	Make3();
	return 0;
}

